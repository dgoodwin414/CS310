/*
* Student Name: Dalton Goodwin
* File Name: Ch10Exercise21.cpp
* Date: 5/6/2026
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class bankAccount {
private:
    //stores the customers name
    string customerName;

    //stores the number tied to the account
    int acctNum;

    //stores if the account is checking or saving
    string acctKind;

    //stores how much money is in the account
    double acctBalance;

    //stores the interest rate as a decimal
    double acctRate;

    //keeps track of the next account number to use
    static int nextAcctNum;

public:
    //default constructor
    bankAccount() {
        //sets the customer name to empty
        customerName = "";

        //sets the account number automatically
        acctNum = nextAcctNum;

        //sets the account type to empty
        acctKind = "";

        //sets the balance to zero
        acctBalance = 0.0;

        //sets the rate to zero
        acctRate = 0.0;

        //moves the next account number up by one
        nextAcctNum++;
    }

    //sets the main account information
    void setInfo(string nameIn, string kindIn, double balanceIn, double rateIn) {
        //stores the name entered by the user
        customerName = nameIn;

        //stores the account type entered by the user
        acctKind = kindIn;

        //stores the beginning balance entered by the user
        acctBalance = balanceIn;

        //stores the interest rate entered by the user
        acctRate = rateIn;
    }

    //returns the customers name
    string getName() const {
        return customerName;
    }

    //returns the account number
    int getAcctNum() const {
        return acctNum;
    }

    //returns the account type
    string getAcctKind() const {
        return acctKind;
    }

    //returns the account balance
    double getAcctBalance() const {
        return acctBalance;
    }

    //returns the account interest rate
    double getAcctRate() const {
        return acctRate;
    }

    //adds money into the account
    void makeDeposit(double moneyIn) {
        //checks that the deposit is more than zero
        if (moneyIn > 0) {
            acctBalance = acctBalance + moneyIn;
        }
        else {
            cout << "Deposit has to be more than zero." << endl;
        }
    }

    //takes money out of the account
    void takeMoneyOut(double moneyOut) {
        //checks if the amount is not valid
        if (moneyOut <= 0) {
            cout << "Withdraw amount has to be more than zero." << endl;
        }
        //checks if the account has enough money
        else if (moneyOut > acctBalance) {
            cout << "There is not enough money in this account." << endl;
        }
        else {
            acctBalance = acctBalance - moneyOut;
        }
    }

    //adds the interest to the account balance
    void addInterest() {
        //adds the interest amount onto the current balance
        acctBalance = acctBalance + (acctBalance * acctRate);
    }

    //prints one account
    void printInfo() const {
        //prints the name, number, type, balance, and rate
        cout << left << setw(18) << customerName
             << setw(12) << acctNum
             << setw(12) << acctKind
             << "$" << setw(11) << fixed << setprecision(2) << acctBalance
             << fixed << setprecision(2) << acctRate * 100 << "%" << endl;
    }
};

//sets the first account number that will be used
int bankAccount::nextAcctNum = 1001;

int main() {
    //makes an array that can hold 10 bank accounts
    bankAccount bankList[10];

    //stores how many customers the user wants to enter
    int customerCount;

    //stores the name entered by the user
    string nameEntry;

    //stores the account type entered by the user
    string kindEntry;

    //stores the starting balance entered by the user
    double balanceEntry;

    //stores the interest rate entered by the user
    double rateEntry;

    //sets the money output to show two decimal places
    cout << fixed << showpoint << setprecision(2);

    //asks the user how many accounts they want to enter
    cout << "How many customers do you want to enter? ";
    cin >> customerCount;

    //keeps asking if the number is outside the allowed range
    while (customerCount < 1 || customerCount > 10) {
        cout << "Please enter a number from 1 to 10: ";
        cin >> customerCount;
    }

    //clears the extra enter key before getline is used
    cin.ignore();

    //gets the account information for each customer
    for (int i = 0; i < customerCount; i++) {
        cout << endl;
        cout << "Customer " << i + 1 << " Information" << endl;

        //gets the customers name
        cout << "Customer name: ";
        getline(cin, nameEntry);

        //gets if the account is checking or saving
        cout << "Account type checking/saving: ";
        getline(cin, kindEntry);

        //gets the amount of money the account starts with
        cout << "Starting balance: ";
        cin >> balanceEntry;

        //gets the interest rate as a decimal number
        cout << "Interest rate as a decimal: ";
        cin >> rateEntry;

        //clears the extra enter key before the next name is entered
        cin.ignore();

        //puts the information into the current account
        bankList[i].setInfo(nameEntry, kindEntry, balanceEntry, rateEntry);
    }

    //prints a blank line
    cout << endl;

    //prints the first report title
    cout << "Bank Accounts Before Changes" << endl;

    //prints the headings for the account report
    cout << left << setw(18) << "Name"
         << setw(12) << "Account"
         << setw(12) << "Type"
         << setw(12) << "Balance"
         << "Interest" << endl;

    //prints a line to make the output easier to read
    cout << "------------------------------------------------------------" << endl;

    //prints each account that was entered
    for (int i = 0; i < customerCount; i++) {
        bankList[i].printInfo();
    }

    //checks that there is at least one account to change
    if (customerCount > 0) {
        //adds 100 dollars to the first account
        bankList[0].makeDeposit(100.00);

        //takes 50 dollars out of the first account
        bankList[0].takeMoneyOut(50.00);

        //adds interest to the first account
        bankList[0].addInterest();
    }

    //prints a blank line
    cout << endl;

    //prints the second report title
    cout << "Bank Accounts After Changes" << endl;

    //prints the headings for the updated account report
    cout << left << setw(18) << "Name"
         << setw(12) << "Account"
         << setw(12) << "Type"
         << setw(12) << "Balance"
         << "Interest" << endl;

    //prints a line to make the output easier to read
    cout << "------------------------------------------------------------" << endl;

    //prints each account again after the changes
    for (int i = 0; i < customerCount; i++) {
        bankList[i].printInfo();
    }

    return 0;
}
