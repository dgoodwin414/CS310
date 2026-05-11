/*
* Student Name: Dalton Goodwin
* File Name: week9_discussion.cpp
* Date: 5/10/2026
*/

#include <iostream>
#include <string>
using namespace std;

//base class for a basic bee in the hive
class Bee {
protected:
    string beeName;
    int energy;

public:
    //constructor sets up the bee name and energy
    Bee(string name, int startingEnergy) {
        beeName = name;
        energy = startingEnergy;
    }

    //shows basic bee information
    void showInfo() const {
        cout << "Bee Name: " << beeName << endl;
        cout << "Energy: " << energy << endl;
    }

    //basic bee action
    void fly() const {
        cout << beeName << " flies around the hive." << endl;
    }
};

//child class for a worker bee
class WorkerBee : public Bee {
private:
    int nectarCollected;

public:
    //constructor for worker bee
    WorkerBee(string name, int startingEnergy, int nectar) : Bee(name, startingEnergy) {
        nectarCollected = nectar;
    }

    //shows worker bee collecting nectar
    void collectNectar() const {
        cout << beeName << " collected " << nectarCollected 
             << " drops of nectar." << endl;
    }
};

//child class for a guard bee
class GuardBee : public Bee {
private:
    int stingPower;

public:
    //constructor for guard bee
    GuardBee(string name, int startingEnergy, int power) : Bee(name, startingEnergy) {
        stingPower = power;
    }

    //shows guard bee defending the hive
    void defendHive() const {
        cout << beeName << " defends the hive with " 
             << stingPower << " sting power." << endl;
    }
};

int main() {
    //creates a worker bee object
    WorkerBee honeyScout("Buzzly", 90, 25);

    //creates a guard bee object
    GuardBee hiveGuard("Stinger", 100, 40);

    //shows bee information
    honeyScout.showInfo();
    hiveGuard.showInfo();

    //calls bee actions
    honeyScout.fly();
    hiveGuard.fly();

    //calls child class actions
    honeyScout.collectNectar();
    hiveGuard.defendHive();

    //error 1: this function does not exist in the WorkerBee class
    honeyScout.defendHive();

    //error 2: missing semicolon at the end of this line
    cout << "The hive is active today!" << endl

    return 0;
}
