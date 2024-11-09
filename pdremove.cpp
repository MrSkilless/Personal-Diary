#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <windows.h>

using namespace std;

// Function to set the color of the text
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main() {
    cout << "Enter the date of the diary you want to delete: (xxxx-xx-xx)" << endl;
    string date, line;
    bool deleting = false, found = false;
    vector<string> contents;
    getline(cin, date);
    ifstream infile("diary.txt");

    while (getline(infile, line)) {
        // If the line is the date, set found to true and start deleting
        if (line == date) {
            found = true;
            deleting = true;
            continue;
        }

        // If it is deleting
        if (deleting) {
            // If the line is the end of the entry, stop deleting
            if (line == "--- --- --- --- --- --- --- --- --- ---") {
                deleting = false;
                continue;
            }
            // Otherwise, skip the line
            else
                continue;
        }

        // Otherwise, write the line to the new file
        contents.push_back(line);
    }

    infile.close();

    // Write the contents to the new file
    ofstream outfile("diary.txt", ios::out);
    for (const auto& l: contents)
        outfile << l << endl;
    
    outfile.close();

    if (!found) {
        setColor(12);
        cerr << "No diary found with that date." << endl;
        setColor(15);
        return 1;
    }

    cout << "Successfully deleted diary entry." << endl;

    return 0;
}