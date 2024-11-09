#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

// Set the color of the text
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main() {
    ifstream inFile("diary.txt");

    // If the file can't be opened, exit the program
    if (!inFile) {
        setColor(12);
        cerr << "'diary.txt' can't get opened!" << endl;
        setColor(15);
        return 1;
    }

    string date, line;
    bool found = false, output = false;

    cout << "Enter the date of the diary you want to see: (xxxx-xx-xx) " << endl;
    getline(cin, date);

    while (getline(inFile, line)) {
        // If the date is found, set found to true and start outputting
        if (line == date) {
            found = true;
            output = true;
        }

        // If it is outputting
        if (output) {
            // If the line is the end of the day, stop outputting
            if (line == "--- --- --- --- --- --- --- --- --- ---") {
                cout << line << endl;
                break;
            }
            // Otherwise, just output the line
            else cout << line << endl;
        }
    }

    // If the date was not found, print an error message and return 1
    if (!found) {
        setColor(12);
        cerr << "Invalid date!" << endl;
        setColor(15);
        inFile.close();
        return 1;
    }

    inFile.close();
    return 0;
}
