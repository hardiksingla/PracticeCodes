#include <iostream>
#include <fstream>

using namespace std;

class BankAccount {
private:
    string accountHolderName;
    int accountNumber;
    double balance;

public:
    BankAccount(string name, int number, double initialBalance) {
        accountHolderName = name;
        accountNumber = number;
        balance = initialBalance;
    }

    string getAccountHolderName() const {
        return accountHolderName;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: Rs" << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: Rs" << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient funds." << endl;
        }
    }

    void displayAccountDetails() const {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: Rs" << balance << endl;
    }
};

class Bank {
public:
    static void createAccount(const BankAccount& account) {
        ofstream file("accounts.txt", ios::app);
        if (file.is_open()) {
            file << account.getAccountHolderName() << " "
                 << account.getAccountNumber() << " "
                 << account.getBalance() << endl;
            file.close();
            cout << "Account created successfully." << endl;
        } else {
            cout << "Error opening file." << endl;
        }
    }

    static void displayAccountDetails(int accountNumber) {
        ifstream file("accounts.txt");
        if (file.is_open()) {
            string name;
            int number;
            double balance;
            bool accountFound = false;

            while (file >> name >> number >> balance) {
                if (number == accountNumber) {
                    cout << "Account found. Displaying details:" << endl;
                    cout << "Account Holder: " << name << endl;
                    cout << "Account Number: " << number << endl;
                    cout << "Balance: Rs" << balance << endl;
                    accountFound = true;
                    break;
                }
            }

            if (!accountFound) {
                cout << "Account not found." << endl;
            }

            file.close();
        } else {
            cout << "Error opening file." << endl;
        }
    }
};

int main() {
    BankAccount account1("hardik", 1001, 5000);
    BankAccount account2("singla", 1002, 10000);

    account1.displayAccountDetails();
    cout<<endl;
    account2.displayAccountDetails();
    cout<<endl;

    account1.deposit(200.00);
    account2.withdraw(300.00);

    account1.displayAccountDetails();
    cout<<endl;
    account2.displayAccountDetails();
    cout<<endl;

    Bank::createAccount(account1);
    cout<<endl;
    Bank::createAccount(account2);
    cout<<endl;

    Bank::displayAccountDetails(1001);
    cout<<endl;
    Bank::displayAccountDetails(1003); // Non-existing account

    return 0;
}
