/*
Exercise P5.4. 
Implement a class Account. 
An account has a balance, functions to add
and withdraw money, and a function to 
query the current balance.
Charge a $5 penalty
if an attempt is made to withdraw more money 
than available in the account.
*/

/*
Exercise P5.5. 
Enhance the Account class of Exercise P5.4 to compute interest on the
current balance. 
Then use the Account class to implement the problem from the
beginning of the book: 
An account has an initial balance of 
$10,000, and 6 percent
annual interest is compounded monthly 
until the investment doubles.
*/

#include <iostream>
#include <string>
#include "Account.h"

using namespace std;

int main() {

    double balance = 0;
    string name = "";
    string response;
    cout << "Name of Client: ";
    cin >> name;
    cout << "\n";
    Account client = Account(name, balance);
    cout << "How may I be of assistance Mr./Mrs. " << name << " ?";
    
    bool keepGoing = true;
    
    while (keepGoing == true) {
        cout << "'o' - Open a new account." << "\n";
        cout << "'w' - Withdraw from account." << "\n";
        cout << "'d' - Desposit from account." << "\n";
        cout << "'q' - Quary balance." << "\n";
        cout << "'i' - Quary interest owed." << "\n";
        cout << "'n' - No further assistance needed." << "\n";
        cout << "\n";
        
        double subtr;
        double add;
        double intr;
        int months;
        int days;
        
        cin >> response;
        if (response[0] == 'o' || response[0] == 'O')
        {
            cout << "\n" << "Value of Initial Desposit: $";
            cin >> balance;
            client = Account(name, balance);
            cout << "\n";
        }
        else if (response[0] == 'w' || response[0] == 'W')
        {
            cout << "How much would you like to withdraw? $";
            cin >> subtr;
            balance = client.withdraw(subtr);
            cout << "\n";
        }
        else if (response[0] == 'd' || response[0] == 'D')
        {
            cout << "How much would you like to deposit? $";
            cin >> add;
            balance = client.deposit(add);
            cout << "\n";
        }
        else if (response[0] == 'q' || response[0] == 'Q')
        {
            client.query();
        }
        else if (response[0] == 'i' || response [0] == 'I')
        {
            cout << "\n" << "What was the interest rate? ";
            cin >> intr;
            cout << "\n" << "How many months have passed? ";
            cin >> months;
            cout << "\n" << "How many days have passed? ";
            cin >> days;
            balance = client.computeInterest(balance, intr, months, days);
            cout << "\n" << "New balance: $" << balance;
            cout << "\n";
        }
        else if (response[0] == 'n' || response [0] == 'N') {
            keepGoing = false;
            cout << "\n";
        }
        else {
            cout << "\n\n";
            return 0;
        }
        
    }
    
    cout << "\n\n";
    return 0;
}