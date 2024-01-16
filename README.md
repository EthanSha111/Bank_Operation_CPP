# Bank Account Manager
## Introduction
This Bank Account Manager is a C++ console application that simulates basic operations of a bank account. Users can log in, view their balance, deposit funds, withdraw cash, and review all transactions associated with their account.

## Features
Login Authentication: Validates user login with a static account number and password.

Balance Inquiry: Allows the user to check the current balance of the account.

Deposit: Users can deposit money into their account.

Withdrawal: Users can withdraw money from their account.

Transaction History: Users can view all past transactions.

## How to Use
Clone the repository to your local machine.
Compile the C++ files including account.cpp and main.cpp with a C++ compiler like g++.
Run the compiled executable.
Follow the on-screen prompts to log in and manage the bank account.

## Code Highlights
The main.cpp contains the user interface and the main application flow control.
The isDouble method validates if the user input is a valid double value, which is crucial for financial transactions.
The application uses exception handling to ensure the robustness of
the input mechanism, preventing invalid data from causing runtime errors.
The program adheres to the Object-Oriented Programming (OOP) principles, with an Account class that encapsulates the behavior and data related to a bank account.

## Getting Started
To get started with the Bank Account Manager, follow these steps:

Compile the Program: Use your favorite C++ compiler to compile the program. For example, with g++ you would use:

Copy code
```bash
bashCopy code
g++ -o BankAccountManager account.cpp main.cpp
```

Run the Program: After compiling, run the program by executing the output binary:

```bash
bashCopy code
./BankAccountManager
```
