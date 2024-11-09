#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <regex>
#include <windows.h>
#include <sstream>
#include <iomanip>

using namespace std;

// To set the color
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// To check whether the date is valid
bool isValidDate(const std::string& date) {
    regex datePattern(R"(^(\d{1,4})-(\d{1,2})-(\d{1,2})$)");
    smatch match;
    
    if (regex_match(date, match, datePattern)) {

        int year = std::stoi(match[1].str());
        int month = std::stoi(match[2].str());
        int day = std::stoi(match[3].str());

        if (month < 1 || month > 12) {
            return false;
        }

        const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        int daysInFebruary = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
        int daysInThisMonth = (month == 2) ? daysInFebruary : daysInMonth[month - 1];

        if (day < 1 || day > daysInThisMonth) {
            return false;
        }

        return true;
    }
    return false;
}

// To check whether the date is repeated
bool DateRepeated(const string& date, const string& filename) {
    ifstream file(filename);

    string line;
    set<string> dates; // To store all the dates

    while (getline(file, line)) {
        line.erase(line.find_last_not_of(" \n\r\t") + 1); // To remove the extra spaces
        dates.insert(line); 
    }

    return dates.find(date) != dates.end();
}

// Overwrite if the date is repeated
void OverWrite(const string& date, const string& filename, const vector<string>& newContent) {
    ifstream infile(filename);
    vector<string> oldContent; // To store the old content
    string line;
    bool overwriting = false; // To check if it is overwriting or not

    while (getline(infile, line)) {
        // If the line matches the date, overwrite it
        if (line == date) {
            overwriting = true;
            oldContent.push_back(date);
            for (const auto& l : newContent)
                oldContent.push_back(l);
            continue;
        }

        // Skip the content that shall be overwritten
        if (overwriting) {
            // If the line is the end of the old content, stop overwriting
            if (line == "--- --- --- --- --- --- --- --- --- ---") {
                overwriting = false;
                oldContent.push_back(line);
            }
            // Otherwise, ignore it
            else
                continue;
        }

        // Otherwise, add it to the old content
        else
            oldContent.push_back(line);
    }

    infile.close();

    // Write the content to the file
    ofstream outfile(filename, ios::out);
    for (const auto& l : oldContent)
        outfile << l << endl;
}
int main() {
    ofstream outFile("diary.txt", ios::app);

    // To check if the file is opened
    if (!outFile) {
        setColor(12);
        cerr << "The file can't get opened" << endl;
        setColor(15);
        return 1;
    }

    string date, line;

    cout << "Enter the date (xxxx-xx-xx): " << endl;
    getline(cin, date);

    // To check if the date is valid
    if (!isValidDate(date)) {
        setColor(12);
        cerr << "Invalid Date!" << endl;
        setColor(15);
        return 1;
    }

    // To check if date is repeated
    bool r = DateRepeated(date, "diary.txt");

    // If date is repeated, overwrite the corresponding entry
    if (r) {
        cout << "The date is repeated. You'll overwrite the diary." << endl;
        cout << "Enter the new content: (type a single '.' to finish)" << endl;
        vector<string> newContents;
        while (true) {
            string l;
            getline(cin, l);
            if (l == ".") break;
            newContents.push_back(l);
        }
        OverWrite(date, "diary.txt", newContents);
    }

    // Otherwise, add a new entry
    else {
        outFile << date << endl;
        cout << "Type your diary: (type a single '.' to finish)" << endl;
        while (true) {
            getline(cin, line);
            if (line == ".") break;
            outFile << line << endl;
        }

        outFile << "--- --- --- --- --- --- --- --- --- ---" << endl;
    }

    // Close the file and output a message
    outFile.close();
    cout << "Your diary has been saved in diary.txt." << endl;

    return 0;
}