
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Shape {
protected:
    double radius;

public:
    Shape(double r = 0.0) : radius(r) {}

    void setRadius(double r) {
        radius = r;
    }

    double getRadius() const {
        return radius;
    }
};

class Circle : public Shape {
public:
    Circle(double r = 0.0) : Shape(r) {}

    double area() const {
        return M_PI * radius * radius;
    }
};

void dynamicCircleHandler() {
    vector<Circle> circles;
    int n;
    cout << "Enter number of circles (dynamic): ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        double r;
        cout << "Enter radius for circle " << i + 1 << ": ";
        cin >> r;
        circles.emplace_back(r);
    }

    cout << "\nAreas of Circles (Dynamic Collection):\n";
    for (int i = 0; i < circles.size(); ++i) {
        cout << "Circle " << i + 1 << ": " << circles[i].area() << "\n";
    }
}

void staticCircleHandler() {
    const int SIZE = 3;
    Circle circles[SIZE];

    cout << "\nStatic Collection (Fixed " << SIZE << " circles):\n";
    for (int i = 0; i < SIZE; ++i) {
        double r;
        cout << "Enter radius for circle " << i + 1 << ": ";
        cin >> r;
        circles[i].setRadius(r);
    }

    cout << "\nAreas of Circles (Static Collection):\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << "Circle " << i + 1 << ": " << circles[i].area() << "\n";
    }
}

int main() {
    dynamicCircleHandler();
    staticCircleHandler();

    cout<<"\n\n24CE027_yash Desai\n";
    return 0;
}
