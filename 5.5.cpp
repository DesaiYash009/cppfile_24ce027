
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual double Area() const = 0;
    virtual void display() const = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double Area() const override {
        return length * width;
    }

    void display() const override {
        cout << "Rectangle (Length: " << length << ", Width: " << width << ")";
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double Area() const override {
        return M_PI * radius * radius;
    }

    void display() const override {
        cout << "Circle (Radius: " << radius << ")";
    }
};

int main() {
    vector<shared_ptr<Shape>> shapeCollection;
    int choice, n;

    cout << "How many shapes do you want to enter? ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "\nEnter shape " << i + 1 << " type (1 - Rectangle, 2 - Circle): ";
        cin >> choice;

        if (choice == 1) {
            double l, w;
            cout << "Enter length: ";
            cin >> l;
            cout << "Enter width: ";
            cin >> w;
            shapeCollection.push_back(make_shared<Rectangle>(l, w));
        } else if (choice == 2) {
            double r;
            cout << "Enter radius: ";
            cin >> r;
            shapeCollection.push_back(make_shared<Circle>(r));
        } else {
            cout << "Invalid choice. Skipping.\n";
        }
    }

    cout << "\n--- Area Results ---\n";
    for (size_t i = 0; i < shapeCollection.size(); ++i) {
        cout << i + 1 << ". ";
        shapeCollection[i]->display();
        cout << " => Area = " << shapeCollection[i]->Area() << endl;
    }


    cout<<endl<<"24CE027_yash Desai"<<endl;

    return 0;
}
