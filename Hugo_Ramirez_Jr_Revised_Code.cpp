#include <iostream>
using namespace std;

int main() {
    int score;

    cout << "Enter your test score: ";
    cin >> score;

    if (score >= 90) {
        cout << "Grade: A" << endl;
    }
    else if (score >= 80) {
        cout << "Grade: B" << endl;
    }
    else if (score >= 70) {
        cout << "Grade: C" << endl;
    }
    else {
        cout << "Grade: F" << endl;
    }

    switch (score / 10) {
        case 10:
        case 9:
            cout << "Excellent work!" << endl;
            break;
        case 8:
            cout << "Good job!" << endl;
            break;
        default:
            cout << "Keep studying." << endl;
    }

    return 0;
}
