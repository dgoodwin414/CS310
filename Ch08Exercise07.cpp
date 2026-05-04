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
    const int totalCandidates = 5;

    //stores each candidate last name
    string candidateNames[totalCandidates];

    //stores each candidate vote count
    int ballotCounts[totalCandidates];

    //stores each candidate vote percentage
    double voteShares[totalCandidates];

    //keeps track of all votes entered
    int voteTotal = 0;

    //keeps track of the candidate with the most votes
    int topCandidate = 0;

    //sets up output to show two decimal places
    cout << fixed << showpoint << setprecision(2);

    //gets the candidate names and vote totals from the user
    for (int spot = 0; spot < totalCandidates; spot++) {
        //asks for the candidate last name
        cout << "Enter the last name of candidate " << spot + 1 << ": ";
        cin >> candidateNames[spot];

        //asks for the number of votes the candidate received
        cout << "Enter the number of votes received by " << candidateNames[spot] << ": ";
        cin >> ballotCounts[spot];

        //adds the current candidate votes to the total
        voteTotal += ballotCounts[spot];

        //checks whether the current candidate has more votes than the current winner
        if (ballotCounts[spot] > ballotCounts[topCandidate]) {
            //updates the winner position
            topCandidate = spot;
        }

        //adds a blank line between each candidate entry
        cout << endl;
    }

    //calculates the vote percentage for each candidate
    for (int spot = 0; spot < totalCandidates; spot++) {
        //converts votes to double so the percent is not rounded like integer math
        voteShares[spot] = static_cast<double>(ballotCounts[spot]) / voteTotal * 100;
    }

    //prints the table headings
    cout << left << setw(15) << "Candidate"
        << right << setw(10) << "Votes"
        << setw(15) << "Percent" << endl;

    //prints a divider line under the headings
    cout << "----------------------------------------" << endl;

    //prints each candidate result
    for (int spot = 0; spot < totalCandidates; spot++) {
        //prints the candidate name, votes, and percent of total votes
        cout << left << setw(15) << candidateNames[spot]
            << right << setw(10) << ballotCounts[spot]
            << setw(14) << voteShares[spot] << "%" << endl;
    }

    //adds space before the winner output
    cout << endl;

    //prints the winner of the election
    cout << "The winner of the election is " << candidateNames[topCandidate] << "." << endl;

    return 0;
}
