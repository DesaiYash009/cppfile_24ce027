
#include <iostream>
#include <vector>
using namespace std;

class student {
protected:
    float marks;

public:
    void setmarks(float m) {
        marks = m;
    }

    virtual string computeGrade() = 0;
    virtual ~student() = default;
};

class Undergraduate : public student {
public:
    string computeGrade() override {
        if (marks >= 80) {
            return "A";
        } else if (marks >= 70) {
            return "B";
        } else if (marks >= 60) {
            return "C";
        } else {
            return "F";
        }
    }
};

class Postgraduate : public student {
public:
    string computeGrade() override {
        if (marks >= 90) {
            return "A";
        } else if (marks >= 80) {
            return "B";
        } else if (marks >= 70) {
            return "C";
        } else {
            return "F";
        }
    }
};

int main() {
    vector<student*> students;
    int n;

    cout << "Enter the number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int type;
        float m;

        cout << "\nEnter student type (UG=1 / PG=2): ";
        cin >> type;

        cout << "Enter marks: ";
        cin >> m;

        student* s = nullptr;

        if (type == 1) {
            s = new Undergraduate();
        } else if (type == 2) {
            s = new Postgraduate();
        } else {
            cout << "Invalid student type. Skipping...\n";
            continue;
        }

        s->setmarks(m);
        students.push_back(s);
    }

    cout << "\nStudent Grades:\n";
    for (size_t i = 0; i < students.size(); i++) {
        cout << "Student " << i + 1 << " Grade: " << students[i]->computeGrade() << endl;
    }

    for (student* s : students) {
        delete s;
    }

    cout<<"\n\n24CE027_yash Desai\n";

    return 0;
}
