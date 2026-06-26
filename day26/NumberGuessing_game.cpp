#include <iostream>
using namespace std;

int main(){
    int secretNumber = 67;
    int guess = 0;
    int attempts = 0;
    int maxAttempts = 7;

    cout << "========================================" << endl;
    cout << "    WELCOME TO THE NUMBER MATRIX        " << endl;
    cout << "========================================" << endl;
    cout << "I have locked a secret number between 1 and 100." << endl;
    cout << "You have exactly " << maxAttempts << " attempts to crack it!" << endl;
    cout << "========================================" << endl;

    while (guess != secretNumber && attempts < maxAttempts){
        cout << "\n[Attempt " << attempts + 1 << "/" << maxAttempts << "] Enter your guess: ";
        cin >> guess;
        attempts++;
        if (guess > secretNumber){
            cout << ">>> ALERT: Too high! Lower your coordinates." << endl;
        } else if (guess < secretNumber){
            cout << ">>> ALERT: Too low! Raise your coordinates." << endl;
        } else{
            cout << "\n========================================" << endl;
            cout << "GONGRETULATION YOU FIND IT !" << endl;
            cout << "Congratulations, you found the number in " << attempts << " attempts!" << endl;
            cout << "========================================" << endl;
            return 0;
        }
    }

    cout << "\n========================================" << endl;
    cout << "SYSTEM LOCKED! GAME OVER!" << endl;
    cout << "You ran out of attempts. The secret number was: " << secretNumber << endl;
    cout << "========================================" << endl;

    return 0;
}