#include <iostream>
#include <cstdlib>
#include <string>
#include <windows.h>

using namespace std;

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void showMenu() {
    setColor(9); 
    cout << "===============================" << endl;
    cout << "   Personal Diary CLI v1.0    " << endl;
    cout << "===============================" << endl;

    setColor(15); 
    cout << "\nPlease choose an option from the menu below:\n" << endl;

    cout << "  1. Add or Edit Diary Entry" << endl;
    cout << "  2. List Diaries" << endl;
    cout << "  3. Search Diary" << endl;
    cout << "  4. Remove Diary Entry" << endl;
    cout << "  5. Exit" << endl;

    cout << "\nEnter the number to select an option (1-5): " << endl;
}

void runPdadd() {
    cout << "\n=== Adding/Editing Diary Entry ===\n";
    system("pdadd");
}

void runPdlist() {
    cout << "\n=== Listing Diaries ===\n";
    system("pdlist");
}

void runPdshow() {
    cout << "\n=== Searching Diary ===\n";
    system("pdshow");
}

void runPdremove() {
    cout << "\n=== Removing Diary Entry ===\n";
    system("pdremove");
}

int main() {
    int choice;

    setColor(10);
    cout << "Welcome to your Personal Diary!" << endl;
    setColor(15);

    while (true) {
        showMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                runPdadd();
                system("pause");
                break;
            case 2:
                runPdlist();
                system("pause");
                break;
            case 3:
                runPdshow();
                system("pause");
                break;
            case 4:
                runPdremove();
                system("pause");
                break;
            case 5:
                cout << "\nThank you for using the Personal Diary CLI!" << endl;
                setColor(12);
                cout << "Exiting... Goodbye!" << endl;
                setColor(15);
                system("pause");
                return 0;
            default:
                setColor(14);
                cout << "\nInvalid choice! Please select a valid option (1-5).\n";
                cin.ignore();
                setColor(15);
                system("pause");
        }
        system("cls");
    }
    
    return 0;
}
