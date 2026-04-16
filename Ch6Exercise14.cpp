/*
 *Student Name: Your Name
 *File Name: Chapter6Exercise14.cpp
 *Date: 4/16/2026
 */

#include <iostream>
#include <iomanip>

using namespace std;

//function to calculate the billing amount
double calculateBilling(double hourlyRate, int consultingTime, bool lowIncome) {
    double billingAmount = 0.0;
    double extraTime = 0.0;

    //if the person has low income
    if (lowIncome) {
        //no charge if time is 30 minutes or less
        if (consultingTime <= 30) {
            billingAmount = 0.0;
        }
        else {
            //calculate time over 30 minutes
            extraTime = consultingTime - 30;
            billingAmount = hourlyRate * 0.40 * (extraTime / 60.0);
        }
    }
    else {
        //no charge if time is 20 minutes or less
        if (consultingTime <= 20) {
            billingAmount = 0.0;
        }
        else {
            //calculate time over 20 minutes
            extraTime = consultingTime - 20;
            billingAmount = hourlyRate * 0.70 * (extraTime / 60.0);
        }
    }

    return billingAmount;
}

int main() {
    double hourlyRate;
    int consultingTime;
    char lowIncomeAnswer;
    bool lowIncome;

    //get the hourly rate
    cout << "Enter the hourly rate: $";
    cin >> hourlyRate;

    //get the total consulting time in minutes
    cout << "Enter the total consulting time in minutes: ";
    cin >> consultingTime;

    //ask whether the person has low income
    cout << "Does the person have low income? (Y/N): ";
    cin >> lowIncomeAnswer;

    //convert the answer to true or false
    if (lowIncomeAnswer == 'Y' || lowIncomeAnswer == 'y') {
        lowIncome = true;
    }
    else {
        lowIncome = false;
    }

    //call the function and display the billing amount
    double billingAmount = calculateBilling(hourlyRate, consultingTime, lowIncome);

    cout << fixed << setprecision(2);
    cout << "The billing amount is: $" << billingAmount << endl;

    return 0;
}
