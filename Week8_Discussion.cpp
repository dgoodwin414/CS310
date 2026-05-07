/*
* Student Name: Dalton Goodwin
* File Name: week8_Discussion.cpp
* Date: 5/6/2026
*/

#include <iostream>
#include <string>
using namespace std;

class Instrument {
private:
    string gearTitle;
    string makerLabel;
    bool outOfTune;

public:
    //sets default values when an instrument object is created
    Instrument() {
        gearTitle = "Unknown Instrument";
        makerLabel = "Unknown Maker";
        outOfTune = true;
    }

    //shows when the instrument object is no longer being used
    ~Instrument() {
        cout << "Instrument record closed." << endl;
    }

    //sets the basic instrument information
    void setInstrumentInfo(string title, string maker) {
        gearTitle = title;
        makerLabel = maker;
        outOfTune = true;
    }

    //changes the tuning status after the instrument is tuned
    void tuneInstrument() {
        outOfTune = false;
    }

    //returns the instrument name
    string getInstrumentName() {
        return gearTitle;
    }

    //returns the brand or maker name
    string getMakerLabel() {
        return makerLabel;
    }

    //prints the instrument information
    void printInstrumentInfo() {
        cout << "Instrument: " << gearTitle << endl;
        cout << "Brand: " << makerLabel << endl;

        //checks if the instrument needs tuning
        if (outOfTune) {
            cout << "Tuning Status: Needs Tuning" << endl;
        }
        else {
            cout << "Tuning Status: Ready To Play" << endl;
        }
    }
};

class Musician {
private:
    string stageName;
    string preferredGenre;
    Instrument stageGear;

public:
    //sets default values when a musician object is created
    Musician() {
        stageName = "Unknown Musician";
        preferredGenre = "Unknown Genre";
    }

    //shows when the musician object is no longer being used
    ~Musician() {
        cout << "Musician record closed." << endl;
    }

    //sets the musician information
    void setMusicianInfo(string nameTag, string genreChoice) {
        stageName = nameTag;
        preferredGenre = genreChoice;
    }

    //assigns an instrument to the musician
    void assignInstrument(Instrument pickedGear) {
        stageGear = pickedGear;
        stageGear.tuneInstrument();
    }

    //returns the musician name
    string getMusicianName() {
        return stageName;
    }

    //returns the musician genre
    string getPreferredGenre() {
        return preferredGenre;
    }

    //prints the musician information
    void printMusicianInfo() {
        cout << "Musician Name: " << stageName << endl;
        cout << "Music Style: " << preferredGenre << endl;

        //prints the musician's assigned instrument
        cout << "Main Instrument:" << endl;
        stageGear.printInstrumentInfo()
    }
};

int main() {
    Instrument garageGuitar;
    Musician localBandMate;

    //stores information about the instrument
    garageGuitar.setInstrumentInfo("Electric Guitar", "Fender");

    //stores information about the musician
    localBandMate.setMusicianInfo("Jace", "Rock");

    //assigns the guitar to the musician
    localBandMate.assignInstrument(garageGuitar);

    //prints the musician and instrument information
    localBandMate.printMusicianInfo();

    //prints the instrument name by using the musician object
    cout << "Instrument For Tonight: " << localBandMate.getInstrumentName() << endl;

    return 0;
}
