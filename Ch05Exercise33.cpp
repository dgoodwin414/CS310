/*
* Student Name: Dalton Goodwin
* File Name: Ch04Exercise16.cpp
* Date: 4/9/2026
*/

#include <iostream>
using namespace std;

int main() {
    //declare the variables
    int a, b, t;
    int dishes = 0;
    int timeUsed = 0;
    int currentDishTime;

    //ask the user for the time needed for the first dish
    cout << "Enter the time for the first dish (a): ";
    cin >> a;

    //ask the user for how much extra time each new dish takes
    cout << "Enter the extra time for each following dish (b): ";
    cin >> b;

    //ask the user for the total amount of time available
    cout << "Enter the total available time (t): ";
    cin >> t;

    //start with the first dish time
    currentDishTime = a;

    //repeat as long as there is enough time to make another dish
    while (timeUsed + currentDishTime <= t) {
        //add the current dish time to the total time used
        timeUsed += currentDishTime;

        //increase the number of dishes completed
        dishes++;

        //increase the time for the next dish
        currentDishTime += b;
    }

    //show the final number of dishes Bianca can prepare
    cout << "Bianca can prepare " << dishes << " dishes." << endl;

    //end the program
    return 0;
}
