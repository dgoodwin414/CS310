/*
* Student Name: Dalton Goodwin
* File Name: week8_Discussion
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

    //changes the tuning status if the instrument needs work again
    void markNeedsTuning() {
        outOfTune = true;
    }

    //prints the instrument information
    void printInstrumentInfo() {
        cout << "Instrument: " << gearTitle << endl;
        cout << "Brand: " << makerLabel << endl;

        //checks if the instrument needs to be tuned
        if (outOfTune) {
            cout << "Tuning Status: Needs Tuning" << endl;
        }
        else {
            cout << "Tuning Status: Ready To Play" << endl;
        }
    }

    //returns the instrument name
    string getInstrumentName() {
        return gearTitle;
    }
};

class Musician {
private:
    string stageName;
    string preferredGenre;
    Instrument stageGear;

public:
    //sets the musician information
    void setMusicianInfo(string nameTag, string genreChoice) {
        stageName = nameTag;
        preferredGenre = genreChoice;
    }

    //assigns the main instrument to the musician
    void assignInstrument(Instrument pickedGear) {
        stageGear = pickedGear;
        stageGear.tuneInstrument();
    }

    //prints the musician information
    void printMusicianInfo() {
        cout << "Musician Name: " << stageName << endl;
        cout << "Music Style: " << preferredGenre << endl;

        //prints the musician's main instrument
        cout << "Main Instrument:" << endl;
        stageGear.printInstrumentInfo()
    }

    //returns the musician name
    string getMusicianName() {
        return stageName;
    }
};

int main() {
    Instrument garageGuitar;
    Musician localBandMate;

    //stores information about the instrument
    garageGuitar.setInstrumentInfo("Electric Guitar", "Fender");

    //stores information about the musician
    localBandMate.setMusicianInfo("Jace", "Rock");

    //assigns the guitar to the band member
    localBandMate.assignInstrument(garageGuitar);

    //prints the full musician record
    localBandMate.printMusicianInfo();

    //prints the instrument name by using the musician object
    cout << "Instrument For Tonight: " << localBandMate.getInstrumentName() << endl;

    return 0;
}
