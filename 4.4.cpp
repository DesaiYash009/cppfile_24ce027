
#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Transaction {
    string type;
    double amount;
};
class BankAccount {
protected:
    int accountNumber;
    double balance;
    vector<Transaction> history;
public:
    BankAccount(int accNum, double bal) : accountNumber(accNum), balance(bal) {}
    virtual ~BankAccount() {}

    virtual void deposit(double amount) {
        balance += amount;
        history.push_back({"deposit", amount});
    }

    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            history.push_back({"withdraw", amount});
        } else {
            cout << "Insufficient balance\n";
        }
    }

    void undoLastTransaction() {
        if (!history.empty()) {
            Transaction last = history.back();
            history.pop_back();
            if (last.type == "deposit") {
                balance -= last.amount;
            } else if (last.type == "withdraw") {
                balance += last.amount;
            }
        } else {
            cout << "No transaction to undo\n";
        }
    }

    void showBalance() const {
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
    double interestRate;
public:
    SavingsAccount(int accNum, double bal, double rate) : BankAccount(accNum, bal), interestRate(rate) {}

    void applyInterest() {
        double interest = balance * interestRate / 100;
        deposit(interest);
    }
};

class CurrentAccount : public BankAccount {
    double overdraftLimit;
public:
    CurrentAccount(int accNum, double bal, double limit) : BankAccount(accNum, bal), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (balance + overdraftLimit >= amount) {
            balance -= amount;
            history.push_back({"withdraw", amount});
        } else {
            cout << "Overdraft limit exceeded\n";
        }
    }
};

int main() {
    SavingsAccount sa(1001, 5000, 3.5);
    sa.deposit(1000);
    sa.withdraw(700);
    sa.applyInterest();
    sa.showBalance();
    sa.undoLastTransaction();
    sa.showBalance();

    CurrentAccount ca(2001, 3000, 1000);
    ca.withdraw(3500);
    ca.deposit(500);
    ca.showBalance();
    ca.undoLastTransaction();
    ca.showBalance();


    cout<<endl<<"24CE027_yash desai"<<endl;
    return 0;
}
