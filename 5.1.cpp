
#include <iostream>
#include <vector>
using namespace std;

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    double add(int a, double b) {
        return a + b;
    }
};

int main() {
    Calculator calc;

    vector<double> stlResults;
    stlResults.push_back(calc.add(20, 30));
    stlResults.push_back(calc.add(2.4, 6.7));
    stlResults.push_back(calc.add(20, 3.89));

    cout << "Results using STL vector:" << endl;
    for (size_t i = 0; i < stlResults.size(); i++) {
        cout << "Result " << i + 1 << ": " << stlResults[i] << endl;
    }
    cout << endl;


    double nonstl[3];
    nonstl[0] = calc.add(20, 10);
    nonstl[1] = calc.add(2.3, 1.7);
    nonstl[2] = calc.add(5, 2.5);

    cout << "Results using non-STL array:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Result " << i + 1 << ": " << nonstl[i] << endl;
    }

    cout<<"\n\n24CE027_yash Desai\n";

    return 0;
}
