#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Question{
    string questionText;
    string optionA;
    string optionB;
    string optionC;
    string optionD;
    char correctOption;
    string category;
};

struct Player{
    string username;
    int correctAnswers;
    int score;
};

int main(){
    Question questionBank[100];
    int totalQuestions = 0;

    ifstream qFile("quiz_questions.txt");
    if (!qFile){
        cout << " Could not load quiz questions file!" << endl;
        return 1;
    }

    while (qFile >> questionBank[totalQuestions].questionText 
                 >> questionBank[totalQuestions].optionA 
                 >> questionBank[totalQuestions].optionB 
                 >> questionBank[totalQuestions].optionC 
                 >> questionBank[totalQuestions].optionD 
                 >> questionBank[totalQuestions].correctOption
                 >> questionBank[totalQuestions].category) {
        totalQuestions++;
    }
    qFile.close();

    if (totalQuestions == 0) {
        cout << ">>> ERROR: The question database is empty." << endl;
        return 1;
    }

    Player activePlayer = {"", 0, 0};
    int choice = 0;
    int catChoice = 0;
    char playerAnswer;

    cout << "==================================================" << endl;
    cout << "||          WELCOME TO MALIK-QUIZ ENGINE         ||" << endl;
    cout << "||        STRUCTURE-BASED FILE ASSESSMENT       ||" << endl;
    cout << "==================================================" << endl;

    cout << "\nCreate your Username without spaces: ";
    cin >> activePlayer.username;

    while (choice != 3) {
        cout << "\n==================================================" << endl;
        cout << "                  CORE MAIN MENU                  " << endl;
        cout << "==================================================" << endl;
        cout << "1. Choose Category & Start Challenge" << endl;
        cout << "2. View Scoreboard " << endl;
        cout << "3. Secure Save & Exit Application" << endl;
        cout << "==================================================" << endl;
        cout << "Select option (1-3): ";
        cin >> choice;

        if (choice == 1) {
            activePlayer.correctAnswers = 0;
            activePlayer.score = 0;

            cout << "\nSelect Category:\n1. Technical\n2. Science\nChoice: ";
            cin >> catChoice;

            string selectedCat = "";
            if (catChoice == 1) selectedCat = "Tech";
            else if (catChoice == 2) selectedCat = "Science";
            else{
                cout << " INVALID CATEGORY. Cancellinging test." << endl;
                continue;
            }

            cout << "\n PREPARING QUIZ ." << endl;
            int currentQuestionNum = 1;

            for (int i = 0; i < totalQuestions; i++){
                if (questionBank[i].category == selectedCat){
                    cout << "\n--------------------------------------------------" << endl;
                    cout << "Question " << currentQuestionNum << ": " << questionBank[i].questionText << endl;
                    cout << "A. " << questionBank[i].optionA << endl;
                    cout << "B. " << questionBank[i].optionB << endl;
                    cout << "C. " << questionBank[i].optionC << endl;
                    cout << "D. " << questionBank[i].optionD << endl;
                    cout << "--------------------------------------------------" << endl;
                    
                    cout << "Your Answer (A, B, C, or D): ";
                    cin >> playerAnswer;

                    if (playerAnswer >= 'a' && playerAnswer <= 'z'){
                        playerAnswer -= 32;
                    }

                    if (playerAnswer == questionBank[i].correctOption){
                        cout << ">>> RESPONSE VERIFIED: Correct! (+10 Points)" << endl;
                        activePlayer.correctAnswers++;
                        activePlayer.score += 10;
                    } else{
                        cout << ">>> RESPONSE VERIFIED: Incorrect. Correct option was " << questionBank[i].correctOption << "." << endl;
                    }
                    currentQuestionNum++;
                }
            }

            cout << "\n==================================================" << endl;
            cout << "                PERFORMANCE REPORT                " << endl;
            cout << "==================================================" << endl;
            cout << "Player Profile : " << activePlayer.username << endl;
            cout << "Category Theme : " << selectedCat << endl;
            cout << "Correct Hits   : " << activePlayer.correctAnswers << endl;
            cout << "Final Score    : " << activePlayer.score << " Points" << endl;
            cout << "==================================================" << endl;

            ofstream historyOut("quiz_history.txt", ios::app);
            if (historyOut){
                historyOut << activePlayer.username << " " 
                           << activePlayer.correctAnswers << " " 
                           << activePlayer.score << endl;
                historyOut.close();
                cout << ">>> SUCCESS: Your performance is updated in leaderboard." << endl;
            }else{
                cout << ">>> ERROR: Performance data could not write to leadrboard." << endl;
            }
        } 
        else if (choice == 2){
            ifstream historyIn("quiz_history.txt");
            cout << "\n==================================================" << endl;
            cout << "              QUIZ LEADERBOARD              " << endl;
            cout << "==================================================" << endl;
            cout << "USERNAME\tCORRECT\t\tSCORE" << endl;
            cout << "--------------------------------------------------" << endl;
            string hName;
            int hCorrect;
            int hScore;
            bool detailsFound = false;

            while (historyIn >> hName >> hCorrect >> hScore){
                cout << hName << "\t\t" << hCorrect << "\t\t" << hScore << " pts" << endl;
                detailsFound = true;
            }
            historyIn.close();

            if (!detailsFound){
                cout << "\t--- No recorded yet ---" << endl;
            }
            cout << "==================================================" << endl;
        } 
        else if (choice == 3){
            cout << "\n SHUTTING DOWN ENGINE SAFELY..." << endl;
        } 
        else{
            cout << " ERROR: Selection operation not recognized." << endl;
        }
    }

    cout << "\n==================================================" << endl;
    cout << "||        QUIZ TERMINATED. YOU CLEARED      ||" << endl;
    cout << "||  Thank you for interacting with MY-QUIZ!   ||" << endl;
    cout << "==================================================" << endl;

    return 0;
}