
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void displayCollection(const vector<T>& collection) {
    cout << "\nNumbers is: ";
    for (int i = 0; i < collection.size(); i++) {
        cout << collection[i] << " ";
    }
    cout << endl;
}

template <typename T>
void reverseCollection(vector<T>& collection) {
    int n = collection.size();
    for (int i = 0; i < n / 2; i++) {
        T temp = collection[i];
        collection[i] = collection[n - 1 - i];
        collection[n - 1 - i] = temp;
    }
}

template <typename T>
T findMaximum(const vector<T>& collection) {
    T maxVal = collection[0];
    for (int i = 1; i < collection.size(); i++) {
        if (collection[i] > maxVal) {
            maxVal = collection[i];
        }
    }
    return maxVal;
}

int main() {
    int choice, size;

    cout << "Choose data type:\n";
    cout << "1. Integer\n2. Float\n3. Character\n";
    cout<<"Enter the choice:";
    cin >> choice;

    cout << "Enter number of elements: ";
    cin >> size;

    if (choice == 1) {
        vector<int> data(size);
        cout << "Enter " << size << " integers:\n";
        for (int i = 0; i < size; i++) {
            cin >> data[i];
        }

        displayCollection(data);
        cout << "Maximum: " << findMaximum(data) << endl;
        reverseCollection(data);
        cout << "Reversed: ";
        displayCollection(data);
    }
    else if (choice == 2) {
        vector<float> data(size);
        cout << "Enter " << size << " floating-point numbers:\n";

        for (int i = 0; i < size; i++) {
            cin >> data[i];
        }

        displayCollection(data);
        cout << "Maximum: " << findMaximum(data) << endl;
        reverseCollection(data);
        cout << "Reversed: ";
        displayCollection(data);
    }
    else if (choice == 3) {
        vector<char> data(size);
        cout << "Enter " << size << " characters:\n";
        for (int i = 0; i < size; i++) {
            cin >> data[i];
        }

        displayCollection(data);
        cout << "Maximum: " << findMaximum(data) << endl;
        reverseCollection(data);
        cout << "Reversed: ";
        displayCollection(data);
    }
    else {
        cout << "Invalid choice" << endl;
    }

    cout<<"\n\n24CE027_yash desai\n";

    return 0;
}

