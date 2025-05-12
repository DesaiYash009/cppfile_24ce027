

#include <iostream>
#include <vector>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:

    Complex() : real(0), imag(0) {}
    Complex(double r, double i) : real(r), imag(i) {}


    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;
        if (c.imag >= 0)
            out << " + " << c.imag << "i";
        else
            out << " - " << -c.imag << "i";
        return out;
    }

    friend istream& operator>>(istream& in, Complex& c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }
};

Complex Add(const vector<Complex>& list) {
    Complex sum;
    for (const auto& c : list) {
        sum = sum + c;
    }
    return sum;
}

Complex Subtract(const vector<Complex>& list) {
    if (list.empty()) return Complex();
    Complex result = list[0];
    for (size_t i = 1; i < list.size(); ++i) {
        result = result - list[i];
    }
    return result;
}

int main() {
    int n;
    cout << "Enter number of complex numbers: ";
    cin >> n;

    vector<Complex> numbers(n);
    for (int i = 0; i < n; ++i) {
        cout << "\nComplex number " << i + 1 << ":\n";
        cin >> numbers[i];
    }

    Complex sum = Add(numbers);
    Complex diff =Subtract(numbers);

    cout << "\nSum of all complex numbers: " << sum << endl;
    cout << "\nSubtraction result: " << diff << endl;

    cout<<"\n\n24CE027_yash Desai\n";

    return 0;
}
