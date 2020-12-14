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
    SavingsAccount(int, int);
    void deposit();
    void display();
    void withdraw();
};
//Constructor for the SavingsAccount class, takes user input for initial dollar and cents values.
//William Box
SavingsAccount::SavingsAccount(int inital_dollars, int initial_cents){
    dollars = inital_dollars;
    cents = initial_cents;
}

void SavingsAccount::deposit() {
    // Deposit function. Asks if user wants to deposit. If user inputs right character, changes the "dollars" and "cents" variables accordingly.
    int interim_dollars=0;
    int interim_cents=0;

    cout << "Please input dollars to be deposited" << endl;
    cin >> interim_dollars;
    cout << "Please input cents to be deposited" << endl;
    cin >> interim_cents;

    dollars += interim_dollars;
    cents += interim_cents;
}
//The purpose of this function is to subtract money from this object, and it does this by asking how much you wish to withdraw from the account, and updating the variables accordingly.
//Erik Brooks
void SavingsAccount::withdraw(){
    int amount = 0;

    cout << "How many dollars do you want to withdraw?" << endl;
    cin >> amount;
    dollars -= amount;
    
    cout << "How many cents do you want to withdraw"<<endl;
    cin >> amount;
    cents -= amount;
}
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
    int initial_dollars = 0;
    int initial_cents = 0;
    char c;

    cout << "Please input the initial dollars" << endl;
    cin >> initial_dollars;
    cout << "Please input the initial cents" << endl;
    cin >> initial_cents;

    SavingsAccount savings_account = SavingsAccount(initial_dollars, initial_cents);

    while (true) {
        cout << "Would you like to make a deposit? Y or y for yes." << endl;
        cin >> c;
        if (c == 'y' || c == 'Y')
            savings_account.deposit();
        else  if (c == 'n' || c == 'N') break;
    }

    while (true) {
        cout << "Would you like to make a withdrawal? Y or y for yes." << endl;
        cin >> c;
        if (c == 'y' || c == 'Y')
            savings_account.withdraw();
        else  if (c == 'n' || c == 'N') break;
    }
    savings_account.display();
}
