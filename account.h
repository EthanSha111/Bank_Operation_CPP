#ifndef ACCOUNT_H // Header guard start
#define ACCOUNT_H // Header guard define
#include <string>
#include <vector>
#include "transaction.h"
// Don't use namespace std as it will pollute the namespace

class account
{
private:
    static int last_account_no; // Static variable to track last account number
    int account_no;
    double balance;
    std::string password;
    std::vector<transaction> transactions;

public:
    account();                                            // Default constructor
    account(const std::string &password, double balance); // Parameterized constructor

    // Member functions
    void showBalance() const;
    int deposit(double amount);
    int withdraw(double amount);
    void showAllTransactions() const; // Make sure this is consistent with .cpp file

    // Getter and setter methods
    int getAccountNo() const;
    double getBalance() const; // Ensure consistent with .cpp file
    const std::string &getPassword() const;
    void setPassword(const std::string &new_password);
};

#endif
