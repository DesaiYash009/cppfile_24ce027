
#include <iostream>
#include <queue>
using namespace std;

class Fahrenheit;

class Celsius {
private:
    double tempC;

public:
    Celsius(double c = 0.0) : tempC(c) {}

    double getTemp() const {
        return tempC;
    }

    operator Fahrenheit();

    bool operator==(const Fahrenheit& f);
};

class Fahrenheit {
private:
    double tempF;

public:
    Fahrenheit(double f = 32.0) : tempF(f) {}

    double getTemp() const {
        return tempF;
    }

    operator Celsius() {
        return Celsius((tempF - 32) * 5 / 9);
    }

    bool operator==(const Celsius& c) {
        return c.getTemp() == ((tempF - 32) * 5 / 9);
    }
};

Celsius::operator Fahrenheit() {
    return Fahrenheit(tempC * 9 / 5 + 32);
}

bool Celsius::operator==(const Fahrenheit& f) {
    return tempC == ((f.getTemp() - 32) * 5 / 9);
}

void storeUsingQueue() {
    queue<Celsius> tempQueue;
    int n;
    cout << "\nEnter number of temperatures(Queue) ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        double temp;
        cout << "Enter Celsius temperature :";
        cin >> temp;
        tempQueue.push(Celsius(temp));
    }

    cout << "\nQueue (FIFO):\n";
    while (!tempQueue.empty()) {
        Celsius c = tempQueue.front();
        Fahrenheit f = c;
        cout << c.getTemp() << "C = " << f.getTemp() << "F\n";
        tempQueue.pop();
    }
}

void storeUsingArray() {
    int n;
    cout << "\nEnter number of temperatures(Array) :";
    cin >> n;
    if (n > 100) n = 100;

    Celsius tempArray[100];
    for (int i = 0; i < n; ++i) {
        double temp;
        cout << "Enter Celsius temperature : ";
        cin >> temp;
        tempArray[i] = Celsius(temp);
    }

    cout << "\nArray (Static Storage):\n";
    for (int i = 0; i < n; ++i) {
        Fahrenheit f = tempArray[i];
        cout << tempArray[i].getTemp() << "C = " << f.getTemp() << "F\n";
    }
}

int main() {
    double cTemp, fTemp;

    cout << "Enter a Celsius temperature to convert and compare: ";
    cin >> cTemp;
    Celsius c(cTemp);
    Fahrenheit f = c;
    cout << "Converted: " << c.getTemp() << "C = " << f.getTemp() << "F\n";

    cout << "Enter a Fahrenheit temperature to compare: ";
    cin >> fTemp;
    Fahrenheit f2(fTemp);
    if (c == f2)
        cout << "Temperatures are equal!\n";
    else
        cout << "Temperatures are not equal.\n";

    storeUsingQueue();
    storeUsingArray();
    cout<<"\n\n24CE027_yash Desai\n";

    return 0;
}
