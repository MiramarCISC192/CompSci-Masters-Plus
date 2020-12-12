#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class SavingsAccount{
private:
    int dollars;
    int cents;
    // Private function that normalizes the amount of dollars and cents, so that all multiples of 100s in cents are stored in dollars, and cents is never > 100;
    // Austin Folster
    void normalize() {
        cents = (dollars * 100) + cents;
        dollars = cents / 100;
        cents = cents % 100;
    }
public:
    SavingsAccount();
    void deposit();
    void display();
    void withdraw();
};
//Constructor for the SavingsAccount class, takes user input for initial dollar and cents values.
//William Box
SavingsAccount::SavingsAccount(){
    cout << "Please input the initial dollars" << endl;
    cin >> dollars;
    cout << "Please input the initial cents" << endl;
    cin >> cents;
}
void SavingsAccount::deposit() {
    // Deposit function. Asks if user wants to deposit. If user inputs right character, changes the "dollars" and "cents" variables accordingly.
    int interim_dollars=0;
    int interim_cents=0;
    char deposit;
    cout << "Would you like to make a deposit? Y or y for yes. Enter any other value for skipping this step" << endl;
    cin >> deposit;
    if (deposit == 'y' || deposit == 'Y')
    {
        cout << "Please input dollars to be deposited" << endl;
        cin >> interim_dollars;
        cout << "Please input cents to be deposited" << endl;
        cin >> interim_cents;
    }
    dollars += interim_dollars;
    cents += interim_cents;
    SavingsAccount::display();
}
// Withdraw function, Asks if user wants to withdraw money. If they do, the function updates the "dollars" and "cents" values accordingly.
// Written by William Box using the deposit function from Auityan as reference.
void SavingsAccount::withdraw() {
    int interim_dollars=0;
    int interim_cents=0;
    char withdraw;
    cout << "Would you like to make a withdraw? Y or y for yes. Enter any other value for skipping this step" << endl;
    cin >> withdraw;
    if (withdraw == 'y' || withdraw == 'Y')
    {
        cout << "Please input dollars to be withdrawn" << endl;
        cin >> interim_dollars;
        cout << "Please input cents to be withdrawn" << endl;
        cin >> interim_cents;
    }
    dollars -= interim_dollars;
    cents -= interim_cents;
    SavingsAccount::display();
}
//takes no parameters and returns nothing, simply prints out the current amount of dollars and cents after calling normalize()
//Austin Folster
void SavingsAccount::display() {
    normalize();
    cout << "Dollars = " << dollars << "           Cents = " << cents << endl;
}

// main program / loop
// Trevor Brage
int main() {
    SavingsAccount savings_account = SavingsAccount();
    savings_account.display();

    while (true) {
        savings_account.deposit();
        savings_account.withdraw();
    }
}
