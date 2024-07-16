// Create a program that generates a random number and asks the user to guess
// it.Provide feedback on whether the guess is too high or too low until the
// user guesses the correct number.
#include <windows.h>

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int searchSpace;
int randomNumber() {
    return rand() % searchSpace;
}

void loading() {
    cout << "Loading.";
    Sleep(1000);
    cout << ".";
    Sleep(1000);
    cout << ".";
    Sleep(1000);
    cout << ".";
    Sleep(1000);
    cout << ".";
}

void gettingDetails(int userNumber, int randomNum) {
    int difference;
    if (userNumber == randomNum) {
        cout << "Congratulations! You guessed the number!";
        return;
    } else if (userNumber < randomNum) {
        difference = randomNum - userNumber;
        if (difference >= 50) {
            cout << "You are extremely far below the original number, please "
                    "try again...";
        } else if (difference >= 30) {
            cout << "You are very far below the original number, please try "
                    "again...";
        } else if (difference >= 10) {
            cout << "You are quite far below the original number, please try "
                    "again...";
        } else if (difference >= 5) {
            cout << "You are close to the original number, please try again...";
        } else {
            cout << "You are very close to the original number, please try "
                    "again...";
        }
    } else {
        difference = userNumber - randomNum;
        if (difference >= 50) {
            cout << "You are extremely far above the original number, please "
                    "try again...";
        } else if (difference >= 30) {
            cout << "You are very far above the original number, please try "
                    "again...";
        } else if (difference >= 10) {
            cout << "You are quite far above the original number, please try "
                    "again...";
        } else if (difference >= 5) {
            cout << "You are close to the original number, please try again...";
        } else {
            cout << "You are very close to the original number, please try "
                    "again...";
        }
    }
}

void end(int randomNum) {
    cout << endl;
    cout << "______________________________________________________________";
    cout << "You had 5 chances, and you've used all 5 chances\nThe number "
            "is : "
         << randomNum << "\nthank you...";
    cout << "______________________________________________________________";
    cout << endl;
}

void guessNumber(int randomNum, int n) {
    if (n == 0) {
        end(randomNum);
        return;
    }
    cout << endl;
    cout << "_______________________________________________________________";
    cout << endl;

    int userNumber;
    do {
        cout << "Enter your number (must be an integer and smaller than "
             << searchSpace << "): ";

        while (!(cin >> userNumber)) {
            cout << "Invalid input. Please enter an integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (userNumber >= searchSpace) {
            cout << "Error: Your number must be less than " << searchSpace
                 << ". Please try again." << endl;
        }
    } while (userNumber >= searchSpace);

    cout << endl;
    gettingDetails(userNumber, randomNum);
    cout << endl;
    guessNumber(randomNum, n - 1);
}

int main() {
    cout << "Specify the upper limit (0 to your number): ";
    if (!(cin >> searchSpace)) {
        cout << "Invalid input. Please enter a valid number." << endl;
        return 1;
    }

    guessNumber(randomNumber(), 5);

    return 0;
}