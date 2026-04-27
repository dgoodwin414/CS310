/*
* Student Name: Dalton Goodwin
* File Name: Ch08Exercise07.cpp
* Date: 4/27/2026
*/



#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    const int candidateCount = 5;

    //stores each candidate last name
    string lastNames[candidateCount];

    //stores each candidate vote count
    int votes[candidateCount];

    //stores each candidate vote percentage
    double percentages[candidateCount];

    //keeps track of all votes entered
    int totalVotes = 0;

    //keeps track of the candidate with the most votes
    int winnerIndex = 0;

    //sets up output to show two decimal places
    cout << fixed << showpoint << setprecision(2);

    //gets the candidate names and vote totals from the user
    for (int i = 0; i < candidateCount; i++) {
        //asks for the candidate last name
        cout << "Enter the last name of candidate " << i + 1 << ": ";
        cin >> lastNames[i];

        //asks for the number of votes the candidate received
        cout << "Enter the number of votes received by " << lastNames[i] << ": ";
        cin >> votes[i];

        //adds the current candidate votes to the total
        totalVotes += votes[i];

        //checks whether the current candidate has more votes than the current winner
        if (votes[i] > votes[winnerIndex]) {
            //updates the winner position
            winnerIndex = i;
        }

        //adds a blank line between each candidate entry
        cout << endl;
    }

    //calculates the vote percentage for each candidate
    for (int i = 0; i < candidateCount; i++) {
        //converts votes to double so the percent is not rounded like integer math
        percentages[i] = static_cast<double>(votes[i]) / totalVotes * 100;
    }

    //prints the table headings
    cout << left << setw(15) << "Candidate"
        << right << setw(10) << "Votes"
        << setw(15) << "Percent" << endl;

    //prints a divider line under the headings
    cout << "----------------------------------------" << endl;

    //prints each candidate result
    for (int i = 0; i < candidateCount; i++) {
        //prints the candidate name, votes, and percent of total votes
        cout << left << setw(15) << lastNames[i]
            << right << setw(10) << votes[i]
            << setw(14) << percentages[i] << "%" << endl;
    }

    //adds space before the winner output
    cout << endl;

    //prints the winner of the election
    cout << "The winner of the election is " << lastNames[winnerIndex] << "." << endl;

    return 0;
}
