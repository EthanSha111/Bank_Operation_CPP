#include "transaction.h"
#include <iostream>
using namespace std;

transaction::transaction(const string &Date, const string &Type, double Amount)
{
    this->Date = Date;
    this->Type = Type;
    this->Amount = Amount;
}

string transaction::getDate() const
{
    return Date;
}

string transaction::getType() const
{
    return Type;
}

double transaction::getAmount() const
{
    return Amount;
}
