#include <iostream>
using namespace std;

int main() {

    //creates an enum for movie ratings
    enum Rating { G, PG, PG13, R, NC17 };

    //sets the movie rating to PG13
    Rating movieRating = PG13;

    //checks if the movie rating is R
    if (movieRating == R) {
        cout << "This movie is rated R." << endl;
    } else {
        cout << "This movie is not rated R." << endl;
    }

    //sets the next rating to R
    Rating nextRating = R;

    //outputs the numeric value of the enum
    cout << "Next rating value: " << nextRating << endl;

    return 0;
}
