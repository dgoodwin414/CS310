/*
* Student Name: Dalton Goodwin
* File Name: Ch04Exercise16.cpp
* Date: 4/1/2026
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //named constants for option 1 fixed payments
    const double DELIVERY_PAYMENT = 5000.00;
    const double PUBLICATION_PAYMENT = 20000.00;

    //named constant for option 2 royalty rate
    const double FULL_RATE_OPTION_TWO = 0.125;

    //named constants for option 3 royalty rates
    const double LOWER_RATE_OPTION_THREE = 0.10;
    const double HIGHER_RATE_OPTION_THREE = 0.14;

    //named constant for the copy limit in option 3
    const int FIRST_COPY_LIMIT = 4000;

    //stores the net price for one book
    double bookNetPrice;

    //stores the estimated number of books sold
    int estimatedSales;

    //stores the royalty totals for each option
    double royaltyPlanOne;
    double royaltyPlanTwo;
    double royaltyPlanThree;

    //stores the best royalty amount and its matching option
    double highestRoyalty;
    string bestPlan;

    //ask the user for the price of one book
    cout << "Enter the net price of each copy of the novel: ";
    cin >> bookNetPrice;

    //ask the user for the estimated number of copies sold
    cout << "Enter the estimated number of copies that will be sold: ";
    cin >> estimatedSales;

    //option 1 is a fixed total payment
    royaltyPlanOne = DELIVERY_PAYMENT + PUBLICATION_PAYMENT;

    //option 2 pays 12.5 percent for every copy sold
    royaltyPlanTwo = bookNetPrice * estimatedSales * FULL_RATE_OPTION_TWO;

    //option 3 uses two different rates
    if (estimatedSales <= FIRST_COPY_LIMIT)
    {
        //all copies use the lower rate if sales stay at or below 4000
        royaltyPlanThree = bookNetPrice * estimatedSales * LOWER_RATE_OPTION_THREE;
    }
    else
    {
        //first 4000 copies use 10 percent
        //remaining copies use 14 percent
        royaltyPlanThree = (bookNetPrice * FIRST_COPY_LIMIT * LOWER_RATE_OPTION_THREE) +
                           (bookNetPrice * (estimatedSales - FIRST_COPY_LIMIT) * HIGHER_RATE_OPTION_THREE);
    }

    //start by assuming option 1 is the best plan
    highestRoyalty = royaltyPlanOne;
    bestPlan = "Option 1";

    //compare option 2 with the current best plan
    if (royaltyPlanTwo > highestRoyalty)
    {
        highestRoyalty = royaltyPlanTwo;
        bestPlan = "Option 2";
    }

    //compare option 3 with the current best plan
    if (royaltyPlanThree > highestRoyalty)
    {
        highestRoyalty = royaltyPlanThree;
        bestPlan = "Option 3";
    }

    //format decimal output to two places
    cout << fixed << setprecision(2);

    //display the royalty totals
    cout << "\nRoyalties under each option:" << endl;
    cout << "Option 1: $" << royaltyPlanOne << endl;
    cout << "Option 2: $" << royaltyPlanTwo << endl;
    cout << "Option 3: $" << royaltyPlanThree << endl;

    //display the best option
    cout << "\nBest option: " << bestPlan << endl;
    cout << "Highest royalty: $" << highestRoyalty << endl;

    return 0;
}
