#include "account.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

// Method checking if input is double or not
bool isDouble(const string &str)
{
    size_t pos;
    try
    {
        // String to double
        double val = stod(str, &pos);
        // Ensure entire string was processed
        return pos == str.size();
    }
    catch (const invalid_argument &e)
    {
        return false;
    }
    catch (const out_of_range &e)
    {
        return false;
    }
}
int main()
{
    // Initialize the bank accounts
    vector<account> accounts;
    for (int i = 0; i < 10; ++i)
    {
        accounts.push_back(account());
    }

    // Login Window:
    int account_no;
    string password;
    cout << "Login Window:" << endl;
    cout << "============" << endl;
    cout << "Enter Your Account no: ";
    cin >> account_no;
    cout << "Enter Your password: ";
    cin >> password;
    cin.ignore(); // Clear the input buffer

    // Handling invalid login:
    if (account_no < 1 || account_no > 10 || password != "123")
    {
        cout << "Invalid Log in" << endl;
        return -1;
    }

    // Get the current account
    account &currentAccount = accounts[account_no - 1];

    // Menu/ Main Window
    int choice;
    do
    {
        cout << "Main Window\n";
        cout << "============\n";
        cout << "1. Show Balance\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Show All Transactions\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the input buffer

        switch (choice)
        {
        case 1:
            cout << "Main Window --> Show Balance" << endl;
            cout << string(35, '=') << endl;
            cout << "Your current balance is: $" << currentAccount.getBalance() << endl;
            cout << "Press enter to go back to the Main Window";
            cin.get();
            break;

        case 2:
            cout << "Main Window --> Deposit (Enter the following information)" << endl;
            cout << string(35, '=') << endl;
            double depo;
            cout << "The amount you want to deposit: ";
            while (!(cin >> depo))
            {
                cin.clear();                                         // clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
                cout << "Invalid input, enter a number: ";
            }
            cin.ignore();

            if (currentAccount.deposit(depo))
            {
                cout << "Well done. This was added to your balance successfully. Press enter to go back to the Main Window";
            }
            else
            {
                cout << "Failed to deposit. Press enter to go back to the Main Window";
            }
            cin.get();
            break;

        case 3:
            cout << "Main Window --> Withdraw (Enter the following information)" << endl;
            cout << string(35, '=') << endl;
            double with;
            cout << "The amount you want to withdraw: ";
            while (!(cin >> depo))
            {
                cin.clear();                                         // clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
                cout << "Invalid input, enter a number: ";
            }
            cin.ignore();
            if (currentAccount.withdraw(with))
            {
                cout << "Please take your money then. Press enter to go back to the Main Window";
            }
            else
            {
                cout << "Failed to withdraw. Press enter to go back to the Main Window";
            }
            cin.get();
            break;

        case 4:
            cout << "Main Window --> Show All Transactions" << endl;
            cout << string(35, '=') << endl;
            cout << "\nAccount no: " << currentAccount.getAccountNo() << endl;
            currentAccount.showAllTransactions();
            cout << "Press enter to go back to the Main Window";
            cin.get();
            break;

        case 5:
            // Exiting
            break;

        default:
            cout << "Invalid choice. Press enter to go back to the Main Window";
            cin.get();
            break;
        }

    } while (choice != 5);

    return 0;
}
