#include <iostream>
#include <iomanip> // for formatting
#include <ctime>
#include "account.h"

using namespace std;

string getCurrentDateTime()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    string dateTime(asctime(ltm));
    // prevent a new line
    if (!dateTime.empty() && dateTime.back() == '\n')
    {
        dateTime.pop_back();
    }

    return dateTime;
}

int account::last_account_no = 0;

account::account()
{
    this->password = "123";
    this->balance = 5000;
    this->account_no = ++last_account_no;
}

account::account(const string &password, double balance)
{
    this->password = password;
    this->balance = balance;
    this->account_no = ++last_account_no;
}

int account::getAccountNo() const
{
    return account_no;
}

const string &account::getPassword() const
{
    return password;
}

void account::setPassword(const string &new_password)
{
    password = new_password;
}

double account::getBalance() const
{
    return balance;
}

int account::deposit(double amount)
{
    if (amount > 0)
    {
        balance += amount;
        transactions.push_back(transaction(getCurrentDateTime(), "deposit", amount));
        return 1;
    }
    else
    {
        cout << "Invalid amount for depositing!\n";
        return 0;
    }
}

int account::withdraw(double amount)
{

    if (amount > balance)
    {
        cout << "Insufficient balance to withdraw!\n";
        return 0;
    }
    else if (amount <= balance && amount >= 0)
    {
        balance -= amount;
        transactions.push_back(transaction(getCurrentDateTime(), "withdraw", amount));
        return 1;
    }
    else
    {
        cout << "Invalid amount for withdrawing!\n";
        return 0;
    }
}

void account::showBalance() const
{
    cout << "The current balance is: " << balance << endl;
}

void account::showAllTransactions() const
{
    // Constants for column widths
    const int DATE_WIDTH = 25;
    const int TYPE_WIDTH = 10;
    const int AMOUNT_WIDTH = 10;

    cout << left
         << setw(DATE_WIDTH) << "Date"
         << "|"
         << setw(TYPE_WIDTH) << " Type"
         << "|"
         << setw(AMOUNT_WIDTH) << " Amount" << endl;

    cout << string(DATE_WIDTH + TYPE_WIDTH + AMOUNT_WIDTH + 2, '-') << endl; // +2 for the '|' characters

    for (const auto &trans : transactions)
    {
        cout << left
             << setw(DATE_WIDTH) << trans.getDate() << "|"
             << setw(TYPE_WIDTH) << " " + trans.getType() << "|"
             << setw(AMOUNT_WIDTH) << " " + to_string(trans.getAmount()) << endl;
    }

    cout << string(DATE_WIDTH + TYPE_WIDTH + AMOUNT_WIDTH + 2, '-') << endl;
}
