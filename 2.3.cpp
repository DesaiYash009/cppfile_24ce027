
#include <iostream>
#include <vector>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    BankAccount() {
        accountHolder = "Default Holder";
        accountNumber = 0;
        balance = 0.0;
    }

    BankAccount(string name, int accNum, double initialBalance) {
        accountHolder = name;
        accountNumber = accNum;
        balance = initialBalance;
    }

    void setDetails() {
        cout << "Enter Account Holder Name: ";
        cin.ignore();
        getline(cin, accountHolder);

        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount deposited successfully.\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount.\n";
        } else if (amount > balance) {
            cout << "Insufficient balance. Withdrawal failed.\n";
        } else {
            balance -= amount;
            cout << "Amount withdrawn successfully.\n";
        }
    }

    void displayAccount() {
        cout << "\nAccount Summary\n";
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: Rs." << balance << endl;
    }
};

int main() {
    vector<BankAccount> accounts;
    int choice;

    do {
        cout << "\nBank Account Management\n";
        cout << "(1) Create account with initial details\n";
        cout << "(2) Deposit money\n";
        cout << "(3) Withdraw money\n";
        cout << "(4) View account summaries\n";
        cout << "(5) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                BankAccount acc;
                acc.setDetails();
                accounts.push_back(acc);
                cout << "Account created successfully.\n";
                break;
            }

            case 2: {
                int index;
                double amount;
                cout << "Enter account index (starting from 0): ";
                cin >> index;

                if (index >= 0 && index < accounts.size()) {
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    accounts[index].deposit(amount);
                } else {
                    cout << "Invalid account index.\n";
                }
                break;
            }

            case 3: {
                int index;
                double amount;
                cout << "Enter account index (starting from 0): ";
                cin >> index;

                if (index >= 0 && index < accounts.size()) {
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    accounts[index].withdraw(amount);
                } else {
                    cout << "Invalid account index.\n";
                }
                break;
            }

            case 4: {
                if (accounts.empty()) {
                    cout << "No accounts to display.\n";
                } else {
                    for (int i = 0; i < accounts.size(); i++) {
                        cout << "\nAccount " << i+1 << " Details:";
                        accounts[i].displayAccount();
                    }
                }
                break;
            }

            case 5: {
                cout << "Exiting the system.\n";
                break;
            }

            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    } while (choice != 5);

    cout<<"\n\n24ce027_Yash Desai";

    return 0;
}
