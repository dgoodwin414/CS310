/*
* Student Name: Dalton Goodwin
* File Name: EnumErrors.cpp
* Date: 04/20/2026
*/

#include <iostream>
using namespace std;

//enum to store the different day types
enum DayType { monday, tuesday, wednesday };

//function to display the activity for the selected day
void showActivity(DayType day)
{
    //check if the day is monday
    if (day == monday)
        cout << "Monday is for studying." << endl;

    //check if the day is tuesday
    else if (day == tuesday)
        cout << "Tuesday is for working out." << endl;

    //check if the day is wednesday
    else if (day == wednesday)
        cout << "Wednesday is for relaxing." << endl;

    //if the value does not match any day
    else
        cout << "Invalid day choice." << endl;
}

int main()
{
    //declare a variable to store the user's day choice
    DayType choice

        //ask the user to enter a day
        cout << "Enter 0 for monday, 1 for tuesday, or 2 for wednesday: ";

    //get the user's input
    cin >> choice;

    //call the function to show the activity
    showactivity(choice);

    //display program ending message
    cout << "Program ended." << endl;

    //end the program
    return 0;
}
