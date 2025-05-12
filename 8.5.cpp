#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
int main()
{

    map<string, vector<string>> directory;

    int choice;
    string folderName, fileName;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Create Folder\n";
        cout << "2. Add File to Folder\n";
        cout << "3. Show Directory Structure\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter folder name: ";
            cin >> folderName;

            if (directory.find(folderName) == directory.end()) {
                directory[folderName] = {};
                cout << "Folder created successfully.\n";
            } else {
                cout << "Folder already exists.\n";
            }

        } else if (choice == 2) {
            cout << "Enter folder name: ";
            cin >> folderName;
            cout << "Enter file name: ";
            cin >> fileName;

            if (directory.find(folderName) != directory.end()) {
                directory[folderName].push_back(fileName);
                cout << "File added successfully.\n";
            } else {
                cout << "Folder not found. Please create the folder first.\n";
            }

        } else if (choice == 3) {
            cout << "\nDirectory Structure:\n";

            for (auto it = directory.begin(); it != directory.end(); ++it) {
                cout << "Folder: " << it->first << "\n";
                cout << "Files:\n";

                for (const auto& file : it->second) {
                    cout << "  - " << file << "\n";
                }
            }

        } else if (choice == 4) {
            cout << "Exiting program.\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    cout<<"\n\n24CE027_yash Desai\n";

    return 0;
}
