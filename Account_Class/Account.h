#ifndef Account_h
#define Account_h

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Account
{
public:
    Account();
    Account(string clientName, double& accBalance);
    double computeInterest(double accBalance, double interestRate, int numMonths, int numDays);
    double withdraw(double addToBalance);
    double deposit(double subtrFromBalance);
    void query() const;
private:
    string name;
    double balance;
    double interest;
    int timeDays;
};

Account::Account()
{
    name = "";
    balance = 0;
    interest = 0;
    timeDays = 0;
};

Account::Account(string clientName, double& accBalance)
{
    name = clientName;
    balance = accBalance;
    interest = 0;
    timeDays = 0;
};

double Account::computeInterest(double accBalance, double interestRate, int numMonths, int numDays)
{
    timeDays = (numMonths * 30) + numDays;
    interest = balance * pow((1 + interestRate), (timeDays / 365));
    return interest;
    balance = interest;
};

double Account::withdraw(double addToBalance)
{
    balance += addToBalance;
    return balance;
};

double Account::deposit(double subtrFromBalance)
{
    balance -= subtrFromBalance;
    return balance;
};

void Account::query() const
{
    cout << "\n" << "Balance for " << name << " is: $" << balance << "\n";
};

#endif /* Account_h */
