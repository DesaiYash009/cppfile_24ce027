#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

// Structure to store student data
struct Student {
    char name[50];
    float marks;
    char grade;
};

// User-defined manipulator for setting a fixed width (like setw)
ostream& alignColumn(ostream& os) {
    return os << setw(15) << left;
}

// Function to generate the formatted student report
void generateReport(const char* filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Could not open file \"" << filename << "\" for reading.\n";
        return;
    }

    Student student;

    cout << "\n======= Student Performance Report =======\n";
    cout << alignColumn << "Name"
         << alignColumn << "Marks"
         << alignColumn << "Grade" << endl;
    cout << string(45, '-') << endl;

    // Read and display data from the file line by line
    while (file >> student.name >> student.marks >> student.grade) {
        cout << alignColumn << student.name
             << alignColumn << fixed << setprecision(2) << student.marks
             << alignColumn << student.grade << endl;
    }

    file.close();
}

int main() {
    const char* filename = "students.txt";

    cout << "=== Student Report Generator ===\n";

    generateReport(filename);


    cout<<endl<<"24CE027_yash Desai"<<endl;
    return 0;
}
