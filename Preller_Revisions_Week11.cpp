/*
 * Student Name: Daniel Preller
 * File Name: Week11.cpp
 * Date: 5/27/2026
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>
#include <climits>

using namespace std;

// Function prototypes for functions used within classes
string boolToString(bool value, string trueString, string falseString);
int getIntInRange(int min, int max);

// Enum used for representing types of menu items
enum ItemType {
    None,
    Food,
    Drink
};

// Class for the basic functions of a list required by the menu
template <typename T>
class BasicList {
private:
    int size;
    T* listArray;

public:
    // Default constructor creates an empty list
    BasicList() {
        size = 0;
        listArray = nullptr;
    }

    // Constructor for a specific size
    BasicList(int size) {
        this->size = size;

        if (size > 0) {
            listArray = new T[size];
        } else {
            listArray = nullptr;
        }
    }

    // Destructor releases the dynamic array
    ~BasicList() {
        delete[] listArray;
    }

    // Appends an item to the list
    void add(T item) {
        T* newArray = new T[size + 1];// Creates a new array large enough to hold the new value

        for (int i = 0; i < size; i++) {// Copies values from old array into new array
            newArray[i] = listArray[i];
        }

        newArray[size] = item;// Appends the new item to the end of the array
        delete[] listArray;// Deletes the old array
        listArray = newArray;// Points the array pointer to the new array
        size++;// Updates the internal size
    }

    // Returns the size of the list
    int getSize() const {
        return size;
    }

    // Returns a reference to the specified value
    T& get(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }

        return listArray[index];
    }

    // Overloads [] operator to allow for direct access to list items
    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }

        return listArray[index];
    }
};

// Abstract class that stores name and price information for menu items
class MenuItem {
protected:
    string name;
    double price;

public:
    MenuItem() {
        setName("Item");
        setPrice(0);
    }

    MenuItem(string name, double price) {
        setName(name);
        setPrice(price);
    }

    virtual ~MenuItem() = default;

    void setName(string name) {
        this->name = name;
    }

    void setPrice(double price) {
        this->price = price;
    }

    string getName() const {
        return name;
    }

    virtual double getPrice(int size) {
        return price;
    }

    virtual ItemType getType() {
        return None;
    }

    void printBasicMenuLine() {
        cout << setw(30) << left << name;
        cout << "$" << fixed << setprecision(2) << price << endl;
    }

    virtual void printDetailedMenuLine() = 0;
};

// Represents a food item in a menu
class FoodItem: public MenuItem {
private:
    bool glutenFree;

public:
    FoodItem(): MenuItem() {
        glutenFree = false;
    }

    FoodItem(string name, double price): MenuItem(name, price) {
        glutenFree = false;
    }

    FoodItem(string name, double price, bool glutenFree): MenuItem(name, price) {
        this->glutenFree = glutenFree;
    }

    ItemType getType() override {
        return Food;
    }

    void printDetailedMenuLine() override {
        cout << setw(20) << left << name;
        cout << setw(15) << boolToString(glutenFree, "Yes", "No");
        cout << "$" << fixed << setprecision(2) << price << endl;
    }
};

// Represents a drink item in a menu
class DrinkItem: public MenuItem {
private:
    double smallPrice;
    double largePrice;

public:
    DrinkItem(): DrinkItem("Item", 0) {}

    DrinkItem(string name, double price): MenuItem(name, price) {
        smallPrice = price - 0.50;

        if (smallPrice < 0) {
            smallPrice = 0;
        }

        largePrice = price + 0.50;
    }

    DrinkItem(string name, double price, double smallPrice, double largePrice) : MenuItem(name, price) {
        this->smallPrice = smallPrice;
        this->largePrice = largePrice;
    }

    ItemType getType() override {
        return Drink;
    }

    void printDetailedMenuLine() override {
        cout << setw(20) << left << name;
        cout << "$" << fixed << setprecision(2) << left << setw(9) << smallPrice;
        cout << "$" << fixed << setprecision(2) << left << setw(9) << price;
        cout << "$" << fixed << setprecision(2) << left << setw(9) << largePrice << endl;
    }

    double getPrice(int size) override {
        switch (size) {
            case 1:
                return smallPrice;
            case 2:
                return price;
            case 3:
                return largePrice;
            default:
                throw invalid_argument("Invalid size");
        }
    }
};

// Menu class is used to make a menu of items and to order from it
class Menu {
private:
    string name;
    BasicList<MenuItem*> items;

public:
    Menu(string name) {
        this->setName(name);
    }

    ~Menu() {
        for (int i = 0; i < items.getSize(); i++) {
            delete items[i];
        }
    }

    void setName(string name) {
        this->name = name;
    }

    void addItem(MenuItem* item) {
        items.add(item);
    }

    string getName() const {
        return name;
    }

    ItemType getItemType(int itemNumber) {
        if (itemNumber >= 0 && itemNumber < items.getSize()) {
            return items[itemNumber]->getType();
        }

        throw invalid_argument("Invalid item number");
    }

    void printMenu() {
        cout << "  " << name << " Menu:" << endl;
        cout << "    " << setw(30) << left << "Item" << "Price" << endl;

        for (int itemNumber = 0; itemNumber < items.getSize(); itemNumber++) {
            cout << "  " << itemNumber + 1 << " ";
            items[itemNumber]->printBasicMenuLine();
        }

        cout << endl;
    }

    void printDrinkMenu() {
        cout << "  " << name << " Drink Menu:" << endl;
        cout << "    " << setw(20) << left << "Item" << setw(10) << "Small" << setw(10) << "Regular"
             << setw(10) << "Large" << endl;

        for (int itemNumber = 0; itemNumber < items.getSize(); itemNumber++) {
            if (items[itemNumber]->getType() == Drink) {
                cout << "  " << itemNumber + 1 << " ";
                items[itemNumber]->printDetailedMenuLine();
            }
        }
    }

    void printFoodMenu() {
        cout << "  " << name << " Food Menu:" << endl;
        cout << "    " << setw(20) << left << "Item" << setw(15) << "Gluten-free" << setw(10) << "Price" << endl;

        for (int itemNumber = 0; itemNumber < items.getSize(); itemNumber++) {
            if (items[itemNumber]->getType() == Food) {
                cout << "  " << itemNumber + 1 << " ";
                items[itemNumber]->printDetailedMenuLine();
            }
        }
    }

    void orderItem(int itemNumber, int size, double& total) {
        itemNumber--;

        if (itemNumber < 0 || itemNumber >= items.getSize()) {
            throw invalid_argument("Invalid item number");
        }

        string sizeName = "";

        if (items[itemNumber]->getType() == Drink) {
            switch (size) {
                case 1:
                    sizeName = "small ";
                    break;
                case 2:
                    sizeName = "regular ";
                    break;
                case 3:
                    sizeName = "large ";
                    break;
            }
        }

        total += items[itemNumber]->getPrice(size);
        cout << "\n  Added one " << sizeName << items[itemNumber]->getName() << " to your order." << endl;
        cout << "  Your total is now $" << fixed << setprecision(2) << total << endl;
    }
};

// Function prototypes
void mainMenuLoop(Menu& menu, double& total, int numberOfItems);
void basicMenuLoop(Menu& menu, double& total, int numberOfItems);
void foodMenuLoop(Menu& menu, double& total, int numberOfItems);
void drinkMenuLoop(Menu& menu, double& total, int numberOfItems);

int main() {
    double total = 0.0;
    string cafeName;

    const int NUMBER_OF_FOOD_ITEMS = 4;
    const int NUMBER_OF_DRINK_ITEMS = 3;
    const int NUMBER_OF_ITEMS = NUMBER_OF_FOOD_ITEMS + NUMBER_OF_DRINK_ITEMS;

    string foodItems[NUMBER_OF_FOOD_ITEMS] = {"Bagel", "Muffin", "Parfait", "Croissant"};
    double foodPrices[NUMBER_OF_FOOD_ITEMS] = {3.00, 3.50, 4.00, 3.50};
    bool foodGlutenFreeStatus[NUMBER_OF_FOOD_ITEMS] = {false, false, true, false};

    string drinkItems[NUMBER_OF_DRINK_ITEMS] = {"Coffee", "Tea", "Espresso"};
    double drinkPrices[NUMBER_OF_DRINK_ITEMS] = {3.75, 3.50, 4.00};

    do {
        cout << "\n\n  Please enter a cafe name: ";
        getline(cin, cafeName);
    } while (cafeName.empty());

    Menu menu(cafeName);

    for (int i = 0; i < NUMBER_OF_FOOD_ITEMS; i++) {
        menu.addItem(new FoodItem(foodItems[i], foodPrices[i], foodGlutenFreeStatus[i]));
    }

    for (int i = 0; i < NUMBER_OF_DRINK_ITEMS; i++) {
        menu.addItem(new DrinkItem(drinkItems[i], drinkPrices[i]));
    }

    cout << "  Welcome to " << menu.getName() << "!" << endl;

    mainMenuLoop(menu, total, NUMBER_OF_ITEMS);

    return 0;
}

void mainMenuLoop(Menu& menu, double& total, int numberOfItems) {
    int selection;

    bool continuing = true;

    while (continuing) {
        cout << "\n  Please enter a number to select an option:" << endl;
        cout << "  0 Complete order" << endl;
        cout << "  1 Display simple menu" << endl;
        cout << "  2 Display detailed food menu" << endl;
        cout << "  3 Display detailed drink menu" << endl;
        cout << "  ";

        selection = getIntInRange(0, 3);

        switch (selection) {
            case 0:
                cout << "  Thank you for visiting " << menu.getName() << "! Your total is $" << fixed << setprecision(2) << total << endl;
                continuing = false;
                break;
            case 1:
                basicMenuLoop(menu, total, numberOfItems);
                break;
            case 2:
                foodMenuLoop(menu, total, numberOfItems);
                break;
            case 3:
                drinkMenuLoop(menu, total, numberOfItems);
                break;
        }
    }
}

void basicMenuLoop(Menu& menu, double& total, int numberOfItems) {
    while (true) {
        cout << endl;
        menu.printMenu();
        cout << "  Enter an item number to add an item to your order." << endl;
        cout << "  To go back, enter 0: ";

        int itemSelection = getIntInRange(0, numberOfItems);

        if (itemSelection == 0) {
            break;
        } else {
            menu.orderItem(itemSelection, 2, total);
        }
    }
}

void foodMenuLoop(Menu& menu, double& total, int numberOfItems) {
    while (true) {
        cout << endl;
        menu.printFoodMenu();
        cout << "  Enter an item number to add an item to your order." << endl;
        cout << "  To go back, enter 0: ";

        int itemSelection = getIntInRange(0, numberOfItems);

        if (itemSelection == 0) {
            break;
        } else if (menu.getItemType(itemSelection - 1) != Food) {
            cout << "  That item is not on the food menu." << endl;
        } else {
            menu.orderItem(itemSelection, 2, total);
        }
    }
}

void drinkMenuLoop(Menu& menu, double& total, int numberOfItems) {
    while (true) {
        cout << endl;
        menu.printDrinkMenu();
        cout << "  Enter an item number to add an item to your order." << endl;
        cout << "  To go back, enter 0: ";

        int itemSelection = getIntInRange(0, numberOfItems);

        if (itemSelection == 0) {
            break;
        } else if (menu.getItemType(itemSelection - 1) != Drink) {
            cout << "  That item is not on the drink menu." << endl;
        } else {
            cout << "\n  Please select a size." << endl;
            cout << "  Enter 1 for small, 2 for regular, and 3 for large: ";
            int size = getIntInRange(1, 3);
            menu.orderItem(itemSelection, size, total);
        }
    }
}

int getIntInRange(int min, int max) {
    int userInput;

    while (true) {
        try {
            if (!(cin >> userInput)) {
                throw runtime_error("Invalid input type");
            }

            if (userInput < min || userInput > max) {
                throw runtime_error("Invalid input value");
            }

            cin.ignore(INT_MAX, '\n');
            return userInput;
        } catch (runtime_error& error) {
            cout << "  Input error. Please try again: ";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
    }
}

string boolToString(bool value, string trueString, string falseString) {
    if (value) {
        return trueString;
    } else {
        return falseString;
    }
}
