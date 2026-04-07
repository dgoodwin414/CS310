/*
* Student Name: Dalton Goodwin
* File Name: Ch04Exercise16.cpp
* Date: 4/6/2026
*/

#include <iostream>
using namespace std;

int main() {
    //stores the number of plants watered
    int plantsWatered = 0;

    //stores the number of garden rows
    int gardenRows = 3;

    //stores the total amount of water used
    double totalWater = 0;

    //loops through each garden row
    for (int row = 1; row <= gardenRows; row++) {
        //stores water used for one row
        double waterUsed;

        //asks the user for input
        cout << "Enter gallons used for row " << row << ": ";
        cin >> waterUsed;

        //adds the water used to the total
        totalWater += waterUsed
    }

    //calculates the average water used
    double averageWater = totalWater / rowCount;

    //shows the result
    cout << "Average water used: " << averageWater << endl;

    return 0;
}
