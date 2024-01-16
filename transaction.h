#ifndef TRANSACTION_H // Header guard start
#define TRANSACTION_H // Header guard define
#include <string>

class transaction
{
public:
    // Default
    transaction(const std::string &Date, const std::string &Type, double Amount);

    std::string getDate() const;
    std::string getType() const;
    double getAmount() const;

private:
    std::string Date;
    std::string Type;
    double Amount;
};

#endif