#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
using namespace std;
void playGame(int lowerBound, int upperBound) {
    srand(static_cast<unsigned int>(time(0)));
    // Generate a random number between lowerBound and upperBound (inclusive)
    int secretNumber = rand() % (upperBound - lowerBound + 1) + lowerBound;
    int guess;
    int attempts = 0;
    cout << "Guess the number between " << lowerBound << " and " << upperBound << "!" << endl;
    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;
        if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;
        }
    } while (guess != secretNumber);
}
int main() {
    int lowerBound, upperBound;
    char playAgain;
    cout << "Welcome to the Number Guessing Game!" << endl;
    do {
        cout << "Enter the lower bound of the number range: ";
        cin >> lowerBound;
        cout << "Enter the upper bound of the number range: ";
        cin >> upperBound;
        if (lowerBound >= upperBound) {
            cout << "Invalid range! Lower bound must be less than upper bound." << endl;
            continue;
        }
        playGame(lowerBound, upperBound);
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
    cout << "Thanks for playing!" << endl;
    return 0;
}