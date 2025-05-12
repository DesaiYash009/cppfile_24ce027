#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_LOG = 100;

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    float balance;
    string transactionLog[MAX_LOG];
    int logCount;

    void logTransaction(const string& message) {
        if (logCount < MAX_LOG) {
            transactionLog[logCount++] = message;
        }
    }

public:
    BankAccount(string name, int accNo, float initialBalance = 0.0f) {
        accountHolder = name;
        accountNumber = accNo;
        balance = initialBalance;
        logCount = 0;
        logTransaction("Account created for " + name + " with balance: " + to_string(balance));
    }

    void deposit(float amount) {
        if (amount <= 0) {
            logTransaction("Error: Attempted deposit of non-positive amount: " + to_string(amount));
            cout << "Invalid deposit amount.\n";
            return;
        }
        balance += amount;
        logTransaction("Deposited: " + to_string(amount) + ", New Balance: " + to_string(balance));
        cout << "Deposit successful.\n";
    }

    void withdraw(float amount) {
        if (amount <= 0) {
            logTransaction("Error: Attempted withdrawal of non-positive amount: " + to_string(amount));
            cout << "Invalid withdrawal amount.\n";
            return;
        }
        if (amount > balance) {
            logTransaction("Error: Withdrawal of " + to_string(amount) + " failed due to insufficient funds.");
            cout << "Insufficient balance.\n";
            return;
        }
        balance -= amount;
        logTransaction("Withdrawn: " + to_string(amount) + ", Remaining Balance: " + to_string(balance));
        cout << "Withdrawal successful.\n";
    }

    void displayAccount() const {
        cout << "\nAccount Summary:\n";
        cout << "Holder Name  : " << accountHolder << endl;
        cout << "Account No.  : " << accountNumber << endl;
        cout << "Balance      : $" << fixed << setprecision(2) << balance << endl;
    }

    void displayLog() const {
        cout << "\nTransaction Log:\n";
        for (int i = 0; i < logCount; ++i) {
            cout << i + 1 << ". " << transactionLog[i] << endl;
        }
    }
};

int main() {
    BankAccount user("John Doe", 123456, 1000.0f);

    int choice;
    float amount;

    do {
        cout << "\n==== Bank Menu ====\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Show Account Info\n";
        cout << "4. Show Transaction Log\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                user.deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                user.withdraw(amount);
                break;
            case 3:
                user.displayAccount();
                break;
            case 4:
                user.displayLog();
                break;
            case 5:
                cout << "Thank you for using the banking system.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    cout<<"\n\n24CE027_yash Desai\n";

    return 0;
}
