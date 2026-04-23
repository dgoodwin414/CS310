/*
* Student Name: Dalton Goodwin
* File Name: VowelRemover.cpp
* Date: 04/23/2026
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

//function prototypes
//these functions are written below main
bool checkVowel(char letter);
string takeOutVowels(string text);

int main()
{
    //declare a variable for the text the user enters
    string enteredText;

    //ask the user for a string
    cout << "Enter a string: ";

    //get the whole line so spaces are included
    getline(cin, enteredText);

    //send the string to the function that removes vowels
    enteredText = takeOutVowels(enteredText);

    //show the updated string
    cout << "String after removing vowels: " << enteredText << endl;

    //end the program
    return 0;
}

//this function checks if the character is a vowel
bool checkVowel(char letter)
{
    //make the letter lowercase so capital vowels are still counted
    letter = tolower(letter);

    //compare the letter to each vowel
    if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
    {
        //return true if it is a vowel
        return true;
    }
    else
    {
        //return false if it is not a vowel
        return false;
    }
}

//this function takes vowels out of the string
string takeOutVowels(string text)
{
    //make an empty string for the letters that stay
    string fixedText = "";

    //go through the string one character at a time
    for (int count = 0; count < text.length(); count++)
    {
        //use substr to pull one character from the string
        string oneLetter = text.substr(count, 1);

        //only keep the character if it is not a vowel
        if (!checkVowel(oneLetter[0]))
        {
            //add the character to the new string
            fixedText = fixedText + oneLetter;
        }
    }

    //send the new string back to main
    return fixedText;
}
