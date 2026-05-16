/*
* Student Name: Dalton Goodwin
* File Name: Ch11Exercise13.cpp
* Date: 5/15/2026
*/

#include <iostream>
#include <iomanip>
using namespace std;

//base class for a regular bank account
class bankAccount {
protected:
    //stores the account number
    int acctId;

    //stores how much money is in the account
    double currentFunds;

public:
    //default constructor
    bankAccount() {
        //sets the account number to zero
        acctId = 0;

        //sets the balance to zero
        currentFunds = 0.0;
    }

    //constructor with values
    bankAccount(int idNumber, double openingFunds) {
        //stores the account number that was sent in
        acctId = idNumber;

        //stores the starting balance that was sent in
        currentFunds = openingFunds;
    }

    //sets the account number
    void setAccountNumber(int idNumber) {
        //updates the account number
        acctId = idNumber;
    }

    //returns the account number
    int getAccountNumber() const {
        //sends the account number back to the caller
        return acctId;
    }

    //returns the current balance
    double getBalance() const {
        //sends the current balance back to the caller
        return currentFunds;
    }

    //adds money to the account
    void addDeposit(double depositAmount) {
        //checks that the deposit is a good amount
        if (depositAmount > 0) {
            //adds the deposit to the balance
            currentFunds += depositAmount;
        } else {
            //prints a message when the deposit is not valid
            cout << "Deposit amount must be greater than zero." << endl;
        }
    }

    //takes money out of the account
    virtual void withdraw(double cashOut) {
        //checks for a bad withdrawal amount
        if (cashOut <= 0) {
            //prints a message when the withdrawal is not valid
            cout << "Withdrawal amount must be greater than zero." << endl;
        } else if (cashOut > currentFunds) {
            //prints a message when there is not enough money
            cout << "Not enough money in the account." << endl;
        } else {
            //takes the money out of the balance
            currentFunds -= cashOut;
        }
    }

    //prints the basic account information
    virtual void showAccount() const {
        //formats money to two decimal places
        cout << fixed << setprecision(2);

        //prints the account number
        cout << "Account Number: " << acctId << endl;

        //prints the current balance
        cout << "Balance: $" << currentFunds << endl;
    }
};

//derived class for checking accounts
class checkingAccount : public bankAccount {
private:
    //stores the interest rate for the account
    double yearlyRate;

    //stores the lowest balance allowed before a fee
    double requiredFloor;

    //stores the charge for going below the minimum balance
    double lowBalanceFee;

public:
    //default constructor
    checkingAccount() : bankAccount() {
        //sets the interest rate to zero
        yearlyRate = 0.0;

        //sets the required minimum balance to zero
        requiredFloor = 0.0;

        //sets the service charge to zero
        lowBalanceFee = 0.0;
    }

    //constructor with values
    checkingAccount(int idNumber, double openingFunds, double rate, double floorAmount, double fee)
        : bankAccount(idNumber, openingFunds) {
        //stores the interest rate
        yearlyRate = rate;

        //stores the minimum balance
        requiredFloor = floorAmount;

        //stores the service charge
        lowBalanceFee = fee;
    }

    //sets the interest rate
    void setInterestRate(double rate) {
        //updates the interest rate
        yearlyRate = rate;
    }

    //returns the interest rate
    double getInterestRate() const {
        //sends the interest rate back to the caller
        return yearlyRate;
    }

    //sets the minimum balance
    void setMinimumBalance(double floorAmount) {
        //updates the required minimum balance
        requiredFloor = floorAmount;
    }

    //returns the minimum balance
    double getMinimumBalance() const {
        //sends the minimum balance back to the caller
        return requiredFloor;
    }

    //sets the service charge
    void setServiceCharges(double fee) {
        //updates the low balance fee
        lowBalanceFee = fee;
    }

    //returns the service charge
    double getServiceCharges() const {
        //sends the service charge back to the caller
        return lowBalanceFee;
    }

    //adds interest to the account
    void addMonthlyInterest() {
        //figures out how much interest was earned
        double earnedInterest = currentFunds * yearlyRate;

        //adds the interest to the account balance
        currentFunds += earnedInterest;
    }

    //checks if the balance is under the minimum balance
    bool underRequiredAmount() const {
        //returns true if the account is below the minimum
        return currentFunds < requiredFloor;
    }

    //writes a check from the checking account
    void writeCheck(double checkTotal) {
        //prints the check amount
        cout << "Writing check for $" << fixed << setprecision(2) << checkTotal << endl;

        //uses withdraw to remove the check amount
        withdraw(checkTotal);
    }

    //overrides the base class withdraw function
    void withdraw(double cashOut) override {
        //checks for a bad withdrawal amount
        if (cashOut <= 0) {
            //prints a message when the withdrawal is not valid
            cout << "Withdrawal amount must be greater than zero." << endl;
        } else if (cashOut > currentFunds) {
            //prints a message when there is not enough money
            cout << "Not enough money in the checking account." << endl;
        } else {
            //takes the money out of the checking account
            currentFunds -= cashOut;

            //checks if the balance dropped below the required amount
            if (underRequiredAmount()) {
                //prints a message about the service charge
                cout << "Balance is below the minimum. Service charge applied." << endl;

                //takes out the service charge
                currentFunds -= lowBalanceFee;
            }
        }
    }

    //prints checking account information
    void showAccount() const override {
        //formats money to two decimal places
        cout << fixed << setprecision(2);

        //prints a heading for the checking account
        cout << "Checking Account Information" << endl;

        //prints the account number
        cout << "Account Number: " << acctId << endl;

        //prints the current balance
        cout << "Balance: $" << currentFunds << endl;

        //prints the interest rate as a percent
        cout << "Interest Rate: " << yearlyRate * 100 << "%" << endl;

        //prints the minimum balance
        cout << "Minimum Balance: $" << requiredFloor << endl;

        //prints the low balance fee
        cout << "Service Charge: $" << lowBalanceFee << endl;
    }
};

//derived class for savings accounts
class savingsAccount : public bankAccount {
private:
    //stores the interest rate for the savings account
    double yearlyRate;

public:
    //default constructor
    savingsAccount() : bankAccount() {
        //sets the interest rate to zero
        yearlyRate = 0.0;
    }

    //constructor with values
    savingsAccount(int idNumber, double openingFunds, double rate)
        : bankAccount(idNumber, openingFunds) {
        //stores the interest rate
        yearlyRate = rate;
    }

    //sets the interest rate
    void setInterestRate(double rate) {
        //updates the interest rate
        yearlyRate = rate;
    }

    //returns the interest rate
    double getInterestRate() const {
        //sends the interest rate back to the caller
        return yearlyRate;
    }

    //adds interest to the savings account
    void addInterest() {
        //figures out how much interest was earned
        double earnedInterest = currentFunds * yearlyRate;

        //adds the interest to the account balance
        currentFunds += earnedInterest;
    }

    //overrides the base class withdraw function
    void withdraw(double cashOut) override {
        //checks for a bad withdrawal amount
        if (cashOut <= 0) {
            //prints a message when the withdrawal is not valid
            cout << "Withdrawal amount must be greater than zero." << endl;
        } else if (cashOut > currentFunds) {
            //prints a message when there is not enough money
            cout << "Not enough money in the savings account." << endl;
        } else {
            //takes the money out of the savings account
            currentFunds -= cashOut;
        }
    }

    //prints savings account information
    void showAccount() const override {
        //formats money to two decimal places
        cout << fixed << setprecision(2);

        //prints a heading for the savings account
        cout << "Savings Account Information" << endl;

        //prints the account number
        cout << "Account Number: " << acctId << endl;

        //prints the current balance
        cout << "Balance: $" << currentFunds << endl;

        //prints the interest rate as a percent
        cout << "Interest Rate: " << yearlyRate * 100 << "%" << endl;
    }
};

int main() {
    //formats money to two decimal places
    cout << fixed << setprecision(2);

    //creates a checking account
    checkingAccount townChecking(24501, 850.00, 0.03, 500.00, 25.00);

    //creates a savings account
    savingsAccount rainyDaySavings(78220, 1500.00, 0.045);

    //prints the starting checking account
    cout << "Starting Checking Account:" << endl;

    //shows the starting checking account details
    townChecking.showAccount();

    //adds a blank line
    cout << endl;

    //deposits money into checking
    townChecking.addDeposit(200.00);

    //writes a check from checking
    townChecking.writeCheck(600.00);

    //adds interest to checking
    townChecking.addMonthlyInterest();

    //adds a blank line
    cout << endl;

    //prints the updated checking account
    cout << "Updated Checking Account:" << endl;

    //shows the updated checking account details
    townChecking.showAccount();

    //prints a divider between the accounts
    cout << endl << "-----------------------------" << endl << endl;

    //prints the starting savings account
    cout << "Starting Savings Account:" << endl;

    //shows the starting savings account details
    rainyDaySavings.showAccount();

    //adds a blank line
    cout << endl;

    //deposits money into savings
    rainyDaySavings.addDeposit(300.00);

    //withdraws money from savings
    rainyDaySavings.withdraw(250.00);

    //adds interest to savings
    rainyDaySavings.addInterest();

    //adds a blank line
    cout << endl;

    //prints the updated savings account
    cout << "Updated Savings Account:" << endl;

    //shows the updated savings account details
    rainyDaySavings.showAccount();

    return 0;
}
