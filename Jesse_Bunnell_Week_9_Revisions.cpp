/*
* Student Name: Jesse Bunnell
* File Name: Week9Errors.cpp
* Date: 05/14/2026
*/


// Use virtual functions
#include <iostream>
#include <string>

using namespace std;

// Base Class for all Animals
// 1. Make a parent class called Animal.
// 2. Give every animal a name.
// 3. Give every animal a makeSound() function.
class Animal {

protected:
    string name;

public:
    Animal(string n) : name(n) {}

    virtual void makeSound() {
        cout << name << " makes a sound." << endl;
    }
};

// Child class #1
// 4. Make a Dog class that inherits from Animal.
// 5. Use the Animal constructor to store the dog's name.
// 6. Change makeSound() so the dog says "Woof!"
class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}

    void makeSound() override {
        cout << name << " says Woof!" << endl;
    }
};

// Child class #2
// 7. Make a Cat class that inherits from Animal.
// 8. Use the Animal constructor to store the cat's name.
// 9. Change makeSound() so the cat says "Meow!"
class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {}

    void makeSound() override {
        cout << name << " says Meow!" << endl;
    }
};

int main() {
    // 10. Create a Dog object and a Cat object.
    // 11. Call each object's makeSound() function.
    Dog dog("Buddy");
    Cat cat("Whiskers");

    dog.makeSound();
    cat.makeSound();

    return 0;
}
