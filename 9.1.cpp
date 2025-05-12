#include <iostream>
using namespace std;
int main() {
    float loanAmount;
    float income;
    cout << "Enter the loan amount: ";
    while (!(cin >> loanAmount) || loanAmount < 0) {
        cout << "Invalid input. Please enter a positive number: ";
        cin.clear();
        cin.ignore();
    }
    cout << "Enter your annual income: ";
    while (!(cin >> income) || income <= 0) {
        if (cin.fail()) {
            cout << "Invalid input. Please enter a positive number: ";
        } else if (income == 0) {
            cout << "Income cannot be zero. Enter a valid income: ";
        } else {
            cout << "Income must be a positive number: ";
        }
        cin.clear();
        cin.ignore();
    }
    float ratio = loanAmount / income;
    cout << "\nYour loan-to-income ratio is: " << ratio << endl;
    cout<<"\n\n24CE027_Yash Desai\n";
    return 0;
}
