#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    string accountHolderName;
    string accountNumber;
    double balance;

public:

    BankAccount(string name, string number, double initialBalance)
        : accountHolderName(name), accountNumber(number), balance(initialBalance) {

    }


    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposit of " << amount << " successful. New balance: " << balance << endl;
        } else
        {
            cout << "Invalid deposit amount. Please enter a positive value." << endl;
        }
    }


    void withdraw(double amount)
    {
        if (amount > 0)
            {
            if (balance >= amount)
            {
                balance -= amount;
                cout << "Withdrawal of " << amount << " successful. New balance: " << balance << endl;
            }
            else
            {
                cout << "Insufficient funds. Cannot withdraw " << amount
                          << ". Current balance: " << balance << endl;
            }
        }
        else
        {
            cout << "Invalid withdrawal amount. Please enter a positive value." << endl;
        }
    }

    double getBalance() const
    {
        return balance;
    }

    void displayAccountDetails() const
    {
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: $" << balance << endl;
    }
};

int main()
 {

    BankAccount account1("Yash Desai", "1234567890", 1000.0);

    cout << "\nInitial Account Details:" << endl;
    account1.displayAccountDetails();


    cout << "\nDepositing 500" << endl;
    account1.deposit(500.0);

    cout << "\nWithdrawing 200" <<endl;
    account1.withdraw(200.0);

    cout << "\nWithdrawing 1500" << endl;
    account1.withdraw(1500.0);

    cout << "\nFinal Account Details:" <<endl;
    account1.displayAccountDetails();


    cout << "\nFinal Balance using getBalance(): " << account1.getBalance() << endl;

    cout<<"\n\n24CE027_Yash Desai\n"<<endl;

    return 0;
}
