/*
* Student Name: Dalton Goodwin
* File Name: Ch13Exercise17.cpp
* Date: 5/28/2026
*/

#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

int main() {
    //this program creates 25 random network signal readings
    //each reading is a real number between 10 and 100
    //the program uses a C++11 random number generator
    //the program also uses try, throw, and catch for exception handling

    //this stores the total number of signal readings
    const int totalReadings = 25;

    //this stores the lowest possible signal value
    const double lowSignal = 10.0;

    //this stores the highest possible signal value
    const double highSignal = 100.0;

    //this stores the signal level that will cause a warning
    const double weakSignalLimit = 25.0;

    //this creates a seed for the random number generator
    random_device seed;

    //this creates a basic C++11 random number generator
    default_random_engine generator(seed());

    //this creates real number values between 10 and 100
    uniform_real_distribution<double> signalRange(lowSignal, highSignal);

    //this makes the signal readings show two decimal places
    cout << fixed << setprecision(2);

    //this prints the program title
    cout << "Network Signal Reading Test" << endl;

    //this explains what the program will do
    cout << "This program will generate 25 random network signal readings." << endl;

    //this explains the exception rule
    cout << "If a signal reading is below 25, an exception will be thrown." << endl;

    //this adds a blank line
    cout << endl;

    //this loop creates 25 random signal readings
    for (int count = 1; count <= totalReadings; count++) {
        //this try block holds the code that could throw an exception
        try {
            //this creates one random signal reading
            double signalReading = signalRange(generator);

            //this prints the current reading number
            cout << "Reading " << count << ": " << signalReading << endl;

            //this checks if the signal reading is too weak
            if (signalReading < weakSignalLimit) {
                //this throws an exception message when the signal is weak
                throw "Weak network signal detected.";
            }

            //this message prints only when no exception happens
            cout << "Status: Signal is acceptable." << endl;
        }

        //this catch block handles the exception message
        catch (const char message[]) {
            //this prints the exception message
            cout << "Exception: " << message << endl;

            //this explains what should happen after the warning
            cout << "Status: Technician should inspect this connection." << endl;
        }

        //this adds a blank line after each signal reading
        cout << endl;
    }

    //this prints after all 25 readings are finished
    cout << "Network signal test completed." << endl;

    return 0;
}
