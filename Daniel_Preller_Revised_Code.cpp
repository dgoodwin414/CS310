/*
*Student Name: Daniel Preller
*File Name: Week1.cpp
*Date: 3/25/2026
*/

#include <iostream>
#include <conio.h>

using namespace std;

int main() {
    //gets first user input
    int value1;
    cout << "\n\n  Please enter an integer: ";
    cin >> value1;

    //gets second user input
    int value2;
    cout << "\n\n  Please enter another integer: ";
    cin >> value2;

    cout << "\n\n  " << value1 << " times " << value2 << " equals " << value1 * value2 << endl; //prints results
    getch(); //stops execution until user presses a key

    return 0;
}
