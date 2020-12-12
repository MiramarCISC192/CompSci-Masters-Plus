#include <iostream>
using namespace std;

class SavingsAccount{
    private:
	int dollars;
	int cents;
	// Private function that normalizes the amount of dollars and cents, so that all multiples of 100s in cents are stored in dollars, and cents is never > 100;
	// Austin Folster
    void normalize() {
		dollars = cents / 100;
		cents = cents % 100;
	  }
    public:
    SavingsAccount();
    void deposit();
    void display();
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
    // Deposit function. Asks if user wants to deposit. If user inputs right character, changes the "dolalrs" and "cents" variables accordingly.
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
}
//takes no parameters and returns nothing, simply prints out the current amount of dollars and cents after calling normalize()
//Austin Folster
void SavingsAccount::display() {
  normalize();
  cout << "Dollars = " << dollars << "           Cents = " << cents;
}
