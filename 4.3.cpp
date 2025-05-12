#include <iostream>
#include <vector>
using namespace std;

class FuelType {
protected:
    string fuel;
public:
    FuelType(string f) {
        fuel = f;
    }
    void displayFuel() const {
        cout << "Fuel Type: " << fuel << endl;
    }
};


class Brand {
protected:
    string brandName;
public:
    Brand(string b) {
        brandName = b;
    }
    void displayBrand() const {
        cout << "Brand Name: " << brandName << endl;
    }
};

class Car : public FuelType, public Brand {
public:
    Car(string f, string b) : FuelType(f), Brand(b) { }

    void showCarDetails() const {
        displayBrand();
        displayFuel();
    }
};

int main() {
    vector<Car> serviceQueue;
    int n;

    cout << "Enter number of cars: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string fuel, brand;
        cout << "\nEnter details for Car :\n";
        cout << "Enter Brand Name: ";
        cin >> brand;
        cout << "Enter Fuel Type (Petrol/Diesel/Electric): ";
        cin >> fuel;

        Car c(fuel, brand);
        serviceQueue.push_back(c);
    }

    cout << "\nCars in Service Queue:\n";
    for (int i = 0; i < serviceQueue.size(); ++i) {
        cout << "\nCar " << i + 1 << " Details:\n";
        serviceQueue[i].showCarDetails();
    }
    cout<<"\n\n24CE27_yash Desai\n";
    return 0;
}
