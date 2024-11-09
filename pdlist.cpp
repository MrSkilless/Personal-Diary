#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

// Set color
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main() {
    cout << "Enter 'A' to show all the diaries." << endl;
    cout << "Enter 'L' to list the diaries by date." << endl;

    string alt;
    cin >> alt;

    // Show all the diaries 
    if (alt == "A" || alt == "a") {
        ifstream file("diary.txt");
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
    }

    // List the diaries by date
    else if (alt == "L" || alt == "l") {
        ifstream file("diary.txt");
        string line, dateS, dateE;
        bool foundS = false, foundE = false, output = false, lastOne = false;

        cout << "Enter the start date: (xxxx-xx-xx)" << endl;
        cin >> dateS;
        cout << "Enter the end date: (xxxx-xx-xx)" << endl;
        cin >> dateE;

        while (getline(file, line)) {
            // If the line is the start date, set foundS to true and start outputting
            if (line == dateS) {
                output = true;
                foundS = true;
            }

            // If the line is the end date, set foundE to true and set lastOne to true
            if (line == dateE) {
                lastOne = true;
                foundE = true; 
            }
            
            // If the line is between the start and end date, output it
            if (output && !lastOne)
                cout << line << endl;

            // If the line is in the last diary
            if (output && lastOne) {
                // If the line is not the end of the diary, output it
                if (line != "--- --- --- --- --- --- --- --- --- ---")
                    cout << line << endl;
                // Otherwise, output the line and stop
                else {
                    cout << line << endl;
                    break;
                }
            }
        }

        // If the date was not found, output an error message
        if (!foundS || !foundE) {
            setColor(12);
            cerr << "Anyway, I have to tell you that your input date is actually not valid." << endl;
            setColor(15);
            return 1;
        }
    }
    
    return 0;
}