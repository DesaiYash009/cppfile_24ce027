
#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }

    Point& move(int dx, int dy) {
        this->x += dx;
        this->y += dy;
        return *this;
    }

    void print() {
        cout << "Point is at (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    int x, y;
    cout << "Enter starting x and y: ";
    cin >> x >> y;

    Point p(x, y);

    int dx1, dy1, dx2, dy2;

    cout << "Enter dx and dy for first move: ";
    cin >> dx1 >> dy1;

    cout << "Enter dx and dy for second move: ";
    cin >> dx2 >> dy2;

    p.move(dx1, dy1).move(dx2, dy2);

    p.print();
    cout<<"\n\n24CE027_yash Desai\n";

    return 0;
}
