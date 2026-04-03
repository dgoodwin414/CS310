/*
* Student Name: Dalton Goodwin
* File Name: Week3_Discussion.cpp
* Date: 4/1/2026
*/


#include <iostream>
using namespace std;

int main() {
    //stores the temperature entered by the user
    int temperature;

    //asks the user to enter the outside temperature
    cout << "Enter the outside temperature: ;

        //gets the temperature from the user
        cin >> temperature;

    //checks if the temperature is greater than 90
    if temperature > 90 {
        cout << "It is very hot outside." << endl;
    }
    //checks if the temperature is between 70 and 90
    else if (temperature >= 70 && temperature <= 90) {
        cout << "The weather is warm." << endl;
    }
    //runs if the temperature is below 70
    else {
        cout << "It is cold outside." << endl;
    }

    //checks if the temperature is below freezing
    if (temperature < 32) {
        cout << "It might be snowing." << endl;
    }

    //ends the program
    return 0;
}
