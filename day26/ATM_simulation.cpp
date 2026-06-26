#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct UserAccount {
    int accountNumber;
    int pin;
    string name;
    string accountType; 
    double balance;
    string history1;
    string history2;
    string history3;
    int isAccountActive; 
};

int main(){
    UserAccount database[100];
    int totalUsers = 0;
    ifstream inputFile("atm_users.txt");
    if (!inputFile) {
        cout << "ERROR: Could not open database file (atm_users.txt)." << endl;
        return 1;
    }

    while (inputFile >> database[totalUsers].accountNumber 
                     >> database[totalUsers].pin 
                     >> database[totalUsers].name 
                     >> database[totalUsers].accountType
                     >> database[totalUsers].balance 
                     >> database[totalUsers].history1
                     >> database[totalUsers].history2
                     >> database[totalUsers].history3
                     >> database[totalUsers].isAccountActive) {
        totalUsers++;
    }
    inputFile.close();

    int enteredAccount = 0;
    int enteredPin = 0;
    int userIndex = -1;
    int pinAttempts = 0;
    bool authenticated = false;

    int choice = 0;
    double amount = 0.0;

    cout << "==================================================" << endl;
    cout << "||          WELCOME TO APNA ATM                 ||" << endl;
    cout << "||         24/7 SECURE BANKING PORTAL           ||" << endl;
    cout << "==================================================" << endl;

    cout << "\nPlease enter your three digit Account Number: ";
    cin >> enteredAccount;

    for (int i = 0; i < totalUsers; i++){
        if (database[i].accountNumber == enteredAccount){
            userIndex = i;
            break;
        }
    }

    if (userIndex == -1){
        cout << "\n==================================================" << endl;
        cout << "||  !!! ERROR: ACCOUNT NOT FOUND !!!            ||" << endl;
        cout << "==================================================" << endl;
        return 0;
    }

    if (database[userIndex].isAccountActive == 0){
        cout << "\n==================================================" << endl;
        cout << "||  !!! TRANSACTION TERMINATED: CARD BLOCKED !!! ||" << endl;
        cout << "||  This card has been deactivated security-wise||" << endl;
        cout << "==================================================" << endl;
        return 0;
    }

    while (pinAttempts < 3){
        cout << "[SECURITY] Enter 4-digit PIN for " << database[userIndex].name << ": ";
        cin >> enteredPin;

        if (enteredPin == database[userIndex].pin){
            authenticated = true;
            break;
        } else {
            pinAttempts++;
            cout << ">>> ACCESS DENIED: Invalid PIN." << endl;
            cout << ">>> WARNING: " << 3 - pinAttempts << " attempt(s) remaining." << endl;
        }
    }

    if (!authenticated) {
        database[userIndex].isAccountActive = 0;
        
        ofstream outputFile("atm_users.txt");
        for (int i = 0; i < totalUsers; i++) {
            outputFile << database[i].accountNumber << " "
                       << database[i].pin << " "
                       << database[i].name << " "
                       << database[i].accountType << " "
                       << database[i].balance << " "
                       << database[i].history1 << " "
                       << database[i].history2 << " "
                       << database[i].history3 << " "
                       << database[i].isAccountActive << endl;
        }
        outputFile.close();

        cout << "\n==================================================" << endl;
        cout << "||  !!! SECURITY ALERT: CARD BLOCKED !!!        ||" << endl;
        cout << "||  Maximum PIN attempts reached. Card status   ||" << endl;
        cout << "||  has been updated to BLOCKED in database.    ||" << endl;
        cout << "==================================================" << endl;
        return 0;
    }

    cout << "\n>>> ACCESS GRANTED. WELCOME BACK, " << database[userIndex].name << "!" << endl;

    while (choice != 5) {
        cout << "\n==================================================" << endl;
        cout << "                  APNA MAIN MENU                 " << endl;
        cout << "==================================================" << endl;
        cout << "Account Owner : " << database[userIndex].name << endl;
        cout << "Account Type  : " << database[userIndex].accountType << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "1. Balance Inquiry" << endl;
        cout << "2. Cash Deposit" << endl;
        cout << "3. Cash Withdrawal" << endl;
        cout << "4. Print Passbook (Statement)" << endl;
        cout << "5. Emergency Block Card" << endl;
        cout << "6. Secure Save & Exit" << endl;
        cout << "==================================================" << endl;
        cout << "Select service (1-6): ";
        cin >> choice;

        if (choice == 1){
            cout << "\n>>> FETCHING SECURE BALANCE..." << endl;
            cout << "Account Type: " << database[userIndex].accountType << " | Balance: $" << database[userIndex].balance << endl;
        } 
        else if (choice == 2){
            cout << "Insert cash amount to deposit: $";
            cin >> amount;
            
            if (amount > 0){
                database[userIndex].balance += amount;
                cout << ">>> SUCCESS: $" << amount << " added to your account." << endl;

                database[userIndex].history3 = database[userIndex].history2;
                database[userIndex].history2 = database[userIndex].history1;
                database[userIndex].history1 = "Deposited:+$" + to_string((int)amount);
            }else{
                cout << ">>> ERROR: Invalid amount specified." << endl;
            }
        } 
        else if (choice == 3){
            cout << "Enter amount to withdraw: $";
            cin >> amount;

            if (amount <= 0){
                cout << "ERROR: Invalid amount." << endl;
            } else if (amount > database[userIndex].balance){
                cout << "TRANSACTION FAILED: Insufficient Balance!" << endl;
            } else{
                database[userIndex].balance -= amount;
                cout << ">>> DISPENSING CASH... Please count your bills." << endl;
                cout << ">>> SUCCESS: Withdrawal of $" << amount << " complete." << endl;

                database[userIndex].history3 = database[userIndex].history2;
                database[userIndex].history2 = database[userIndex].history1;
                database[userIndex].history1 = "Withdrew:-$" + to_string((int)amount);
            }
        } 
        else if (choice == 4){
            cout << "\n==================================================" << endl;
            cout << "              PASSBOOK PRINT RUN                  " << endl;
            cout << "==================================================" << endl;
            cout << "Holder Name    : " << database[userIndex].name << endl;
            cout << "Account Type   : " << database[userIndex].accountType << endl;
            cout << "Account Number : " << database[userIndex].accountNumber << endl;
            cout << "--------------------------------------------------" << endl;
            cout << "[Line 1 Update] : " << database[userIndex].history1 << endl;
            cout << "[Line 2 Update] : " << database[userIndex].history2 << endl;
            cout << "[Line 3 Update] : " << database[userIndex].history3 << endl;
            cout << "--------------------------------------------------" << endl;
            cout << "NET BALANCE: $" << database[userIndex].balance << endl;
            cout << "==================================================" << endl;
        } 
        else if (choice == 5){
            char confirm;
            cout << "\n>>> WARNING: Are you sure you want to block your card? (y/n): ";
            cin >> confirm;
            if (confirm == 'y' || confirm == 'Y'){
                database[userIndex].isAccountActive = 0;
                cout << " CARD INTENTIONALLY BLOCKED. TERMINATING SESSION..." << endl;
                break;
            } else{
                cout << " Operation canceled safely." << endl;
            }
        }
        else if (choice == 6){
            cout << "\n COMMITTING UPDATES TO THE CENTRAL FILE BASE..." << endl;
            break;
        } 
        else{
            cout << " ERROR: Operation not recognized." << endl;
        }
    }

    ofstream outputFile("atm_users.txt");
    for (int i = 0; i < totalUsers; i++){
        outputFile << database[i].accountNumber << " "
                   << database[i].pin << " "
                   << database[i].name << " "
                   << database[i].accountType << " "
                   << database[i].balance << " "
                   << database[i].history1 << " "
                   << database[i].history2 << " "
                   << database[i].history3 << " "
                   << database[i].isAccountActive << endl;
    }
    outputFile.close();

    cout << "\n==================================================" << endl;
    cout << "||       FILE UPDATED & CARD SECURELY EJECTED    ||" << endl;
    cout << "||    Thank you for choosing NEXUS ATM CORPS!   ||" << endl;
    cout << "==================================================" << endl;

    return 0;
}