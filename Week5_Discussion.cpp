/*
 *Student Name: Dalton Goodwin
 *File Name: Week5.cpp
 *Date: 4/13/2026
 */

#include <iostream>
using namespace std;

//function prototype for squaring a number
int squareNumber(int num);

//function prototype for showing the answer
void showAnswer(int result);

int main() {
    //stores the number entered by the user
    int number;

    //asks the user to enter a number
    cout << "Enter a number: ";
    cin >> number;

    //calls the function to square the number
    int answer = squareNumber(number);

    //calls the function to display the answer
    showAnswer(answer);

    //ends the program
    return 0;
}

//finds the square of the number entered
int squareNumber(int num) {
    //multiplies the number by itself
    int result = num * num

    //returns the squared value back to main
    return result;
}

//shows the squared result on the screen
void showAnswer(int value) {
    //displays the result for the user
    cout << "The square is: " << result << endl;
}
