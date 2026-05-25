/*
 *Student Name: Dalton Goodwin
 *File Name: Week10_discussion.cpp
 *Date: 5/20/2026
 */


#include <iostream>

using namespace std;

//this program checks basic switch port information using pointers
//the goal is to practice storing addresses and changing values with pointers

int main() {
    //this stores the switch number being checked
    int switchNumber = 7;

    //this stores how many ports are currently open
    int openPorts = 12;

    //this stores how many ports are currently being used
    int usedPorts = 20;

    //this pointer stores the memory address of the switch number
    int* switchPtr = switchNumber;

    //this pointer stores the memory address of the open port count
    int* openPortPtr = &openPorts;

    //this pointer stores the memory address of the used port count
    int* usedPortPtr = &usedPorts

    //this prints the switch number before any updates are made
    cout << "Switch Number: " << *switchPtr << endl;

    //this prints the original number of open ports
    cout << "Open Ports: " << *openPortPtr << endl;

    //this prints the original number of used ports
    cout << "Used Ports: " << *usedPortPtr << endl;

    //this simulates a few devices being unplugged from the switch
    *openPortPtr = *openPortPtr + 3;

    //this lowers the number of used ports after those devices are removed
    usedPortPtr = usedPortPtr - 3;

    //this prints the new number of open ports after the update
    cout << "Updated Open Ports: " << *openPortPtr << endl;

    //this prints the new number of used ports after the update
    cout << "Updated Used Ports: " << usedPortPtr << endl;

    //this prints a final message after the switch record is reviewed
    cout << "Switch record checked" << endl;

    return 0;
}
