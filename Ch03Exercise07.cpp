#include <iostream>
#include <iomanip>
#include <locale>

using namespace std;

int main()
{
    double netBalance;
    double payment;
    double interestRate;
    double averageDailyBalance;
    double interest;
    int d1;
    int d2;

    //get the balance shown on the bill
    cout << "Enter the net balance: ";
    cin >> netBalance;

    //get the payment made
    cout << "Enter the payment amount: ";
    cin >> payment;

    //get the number of days in the billing cycle
    cout << "Enter the number of days in the billing cycle: ";
    cin >> d1;

    //get the number of days payment was made before the billing cycle
    cout << "Enter the number of days payment was made before the billing cycle: ";
    cin >> d2;

    //get the monthly interest rate
    cout << "Enter the interest rate per month: ";
    cin >> interestRate;

    //calculate the average daily balance
    averageDailyBalance = (netBalance * d1 - payment * d2) / d1;

    //calculate the interest on the unpaid balance
    interest = averageDailyBalance * interestRate;

    // format the output to two decimal places with the thousands separator
    cout << fixed << setprecision(2); // set the decimal to two places.
    locale loc(""); // for the thousands separator
    cout.imbue(loc); // for the thousands separator

    //display the average daily balance
    cout << "Average daily balance: $" << averageDailyBalance << endl;

    //display the interest
    cout << "Interest on the unpaid balance: $" << interest << endl;

    return 0;
}