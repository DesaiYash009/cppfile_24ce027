
#include <iostream>
#include <vector>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    int marks[3];

public:

    void inputDetails() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        for (int i = 0; i < 3; i++) {
            cout << "Enter marks for subject " << (i + 1) << ": ";
            cin >> marks[i];
        }
    }
    void displayDetails() {
        cout << "\nStudent Details\n";
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Marks in Subject " << (i + 1) << ": " << marks[i] << endl;
        }
        cout << "Average Marks: " << getAverage() << endl;
    }

    float getAverage() {
        return (marks[0] + marks[1] + marks[2]) / 3.0;
    }
};

int main() {
     Student s;
    vector<Student> students;
    int choice;

    do {
        cout << "\nStudent Record System\n";
        cout << "1. Add student\n";
        cout << "2. View all student records\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            s.inputDetails();
            students.push_back(s);
            cout << "Student added successfully.\n";
            break;
        }

        case 2: {
            if (students.empty()) {
                cout << "No student records available.\n";
            } else {
                for (size_t i = 0; i < students.size(); i++) {
                    cout << "\nStudent " << i + 1 << ":";
                    students[i].displayDetails();
                }
            }
            break;
        }

        case 3:
            cout << "Exiting the program.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 3);

    cout<<"\n\n24CE027_Yash Desai.\n";

    return 0;
}
