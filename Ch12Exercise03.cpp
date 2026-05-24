/*
* Student Name: Dalton Goodwin
* File Name: Ch12Exercise03.cpp
* Date: 5/24/2026
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    int candidateAmount;

    //sets the numbers to show two places after the decimal
    cout << fixed << showpoint << setprecision(2);

    //asks the user how many candidates are part of the election
    cout << "Enter the number of candidates: ";
    cin >> candidateAmount;

    //makes sure the user did not enter zero or a negative number
    if (candidateAmount <= 0)
    {
        //prints an error message if the candidate amount is not valid
        cout << "Error: The number of candidates must be greater than zero." << endl;

        //ends the program because the arrays cannot be made correctly
        return 1;
    }

    cout << endl;

    //makes a dynamic array for the candidate last names
    string* lastNames = new string[candidateAmount];

    //makes a dynamic array for the votes each candidate received
    int* votesReceived = new int[candidateAmount];

    //makes a dynamic array for the percentage of votes each candidate got
    double* votePercent = new double[candidateAmount];

    //keeps track of all the votes entered by the user
    int totalVotes = 0;

    //stores the array spot for whoever is winning
    int winnerSpot = 0;

    //gets the last names and vote totals from the user
    for (int index = 0; index < candidateAmount; index++)
    {
        //shows which candidate the user is entering
        cout << "Enter candidate " << index + 1 << " last name: ";

        //stores the candidate last name in the dynamic array
        cin >> lastNames[index];

        //asks for the number of votes for this candidate
        cout << "Enter votes for " << lastNames[index] << ": ";

        //stores the votes in the dynamic array
        cin >> votesReceived[index];

        //checks that the vote count is not negative
        if (votesReceived[index] < 0)
        {
            //prints an error message for an invalid vote amount
            cout << "Error: Vote totals cannot be negative." << endl;

            //clears the name array before the program exits
            delete[] lastNames;

            //clears the vote array before the program exits
            delete[] votesReceived;

            //clears the percent array before the program exits
            delete[] votePercent;

            //ends the program because the vote data is not valid
            return 1;
        }

        //adds this candidate's votes to the full election total
        totalVotes = totalVotes + votesReceived[index];

        //checks if this candidate has more votes than the current winner
        if (votesReceived[index] > votesReceived[winnerSpot])
        {
            //saves the spot of the candidate with the highest vote count
            winnerSpot = index;
        }

        //adds a blank line after each candidate entry
        cout << endl;
    }

    //checks that the election has at least one vote
    if (totalVotes == 0)
    {
        //prints an error message if all candidates have zero votes
        cout << "Error: The total number of votes must be greater than zero." << endl;

        //clears the name array before the program exits
        delete[] lastNames;

        //clears the vote array before the program exits
        delete[] votesReceived;

        //clears the percent array before the program exits
        delete[] votePercent;

        //ends the program because percentages cannot be calculated
        return 1;
    }

    //figures out each candidate's vote percentage
    for (int index = 0; index < candidateAmount; index++)
    {
        //uses static_cast so the division keeps decimal values
        votePercent[index] = static_cast<double>(votesReceived[index]) / totalVotes * 100;
    }

    //prints a title before showing the results
    cout << "Election Results" << endl;

    //prints a divider line under the title
    cout << "------------------------------------------" << endl;

    //prints the column names for the results table
    cout << left << setw(15) << "Candidate"
         << right << setw(10) << "Votes"
         << setw(15) << "Percent" << endl;

    //prints a line between the headings and the data
    cout << "------------------------------------------" << endl;

    //prints the results for each candidate
    for (int index = 0; index < candidateAmount; index++)
    {
        //prints the candidate name, vote count, and vote percentage
        cout << left << setw(15) << lastNames[index]
             << right << setw(10) << votesReceived[index]
             << setw(14) << votePercent[index] << "%" << endl;
    }

    //prints a line after all candidate results
    cout << "------------------------------------------" << endl;

    //adds a blank line before the winner statement
    cout << endl;

    //prints the candidate with the highest vote count
    cout << "The winner of the election is " << lastNames[winnerSpot] << "." << endl;

    //clears the dynamic array holding candidate names
    delete[] lastNames;

    //clears the dynamic array holding vote counts
    delete[] votesReceived;

    //clears the dynamic array holding vote percentages
    delete[] votePercent;

    //ends the program successfully
    return 0;
}
