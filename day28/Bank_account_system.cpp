#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Account{
    int accountNo;
    double balance;
    string accountType;
    string holderName;
};
void createAccount(){
    ofstream file("bank.txt", ios::app);
    Account a;
    cout << "\n=============================================\n";
    cout << "             OPEN NEW BANK ACCOUNT           \n";
    cout << "=============================================\n";
    cout << " -> Enter Account Number: ";
    cin >> a.accountNo;
    cout << " -> Enter Initial Deposit ($): ";
    cin >> a.balance;
    cout << " -> Enter Account Type (Saving/Current): ";
    cin >> a.accountType;
    cin.ignore();
    cout << " -> Enter Account Holder Name: ";
    getline(cin, a.holderName);

    file << a.accountNo << " " << a.balance << " " << a.accountType << " | " << a.holderName << "\n";
    file.close();
    cout << "\n[+] Account created successfully!\n";
}
void displayAllAccounts(){
    ifstream file("bank.txt");
    if (!file){
        cout << "\n[!] No active bank account records found!\n";
        return;
    }
    Account a;
    string separator;
    cout << "\n========================================================================\n";
    cout << "Acc No\tBalance\t\tType\t\tAccount Holder Name\n";
    cout << "========================================================================\n";

    while (file >> a.accountNo >> a.balance >> a.accountType){
        file >> separator;
        getline(file, a.holderName);
        cout << a.accountNo << "\t$" 
             << a.balance << "\t\t" 
             << a.accountType << "\t\t" 
             << a.holderName << "\n";
    }
    file.close();
    cout << "========================================================================\n";
}
void searchAccount(){
    ifstream file("bank.txt");
    if (!file){
        cout << "\n[!] Bank record not found!\n";
        return;
    }

    int searchNo;
    cout << "\nEnter Account Number : ";
    cin >> searchNo;

    Account a;
    string separator;
    bool found = false;

    while (file >> a.accountNo >> a.balance >> a.accountType){
        file >> separator;
        getline(file, a.holderName);

        if (a.accountNo == searchNo){
            cout << "\n############################################################";
            cout << "\n#                 ACCOUNT HOLDER PROFILE                   #";
            cout << "\n############################################################";
            cout << "\n  ACCOUNT NO   : " << a.accountNo;
            cout << "\n  NAME         :" << a.holderName;
            cout << "\n  ACCOUNT TYPE : " << a.accountType;
            cout << "\n  NET BALANCE  : $" << a.balance;
            cout << "\n############################################################\n";
            found = true;
            break;
        }
    }
    if (!found){
        cout << "\n[-] System mismatch. Target Account Number not registered yet.\n";
    }
    file.close();
}
void depositWithdraw(int actionType){
    ifstream file("bank.txt");
    ofstream temp("temp.txt");
    if (!file){
        cout << "\n[!] Bank record not found!\n";
        return;
    }

    int targetNo;
    cout << "\nEnter Account Number: ";
    cin >> targetNo;
    Account a;
    string separator;
    bool found = false;
    double amount;
    while (file >> a.accountNo >> a.balance >> a.accountType){
        file >> separator;
        getline(file, a.holderName);

        if (a.accountNo == targetNo){
            found = true;
            if (actionType == 1){
                cout << "Enter Amount to Deposit (₹): ";
                cin >> amount;
                a.balance += amount;
                cout << "\n[+] Amount deposited successfully!\n";
            } else {
                cout << "Enter Amount to Withdraw (₹): ";
                cin >> amount;
                if (amount <= a.balance){
                    a.balance -= amount;
                    cout << "\n[+] Cash dispensed successfully!\n";
                } else{
                    cout << "\n[!] Transaction denied: Insufficient funds!\n";
                }
            }
        }
        temp << a.accountNo << " " << a.balance << " " << a.accountType << " |" << a.holderName << "\n";
    }

    file.close();
    temp.close();
    remove("bank.txt");
    rename("temp.txt", "bank.txt");

    if (!found){
        cout << "\n[-] Target account profile missing.\n";
    }
}
void closeAccount(){
    ifstream file("bank.txt");
    ofstream temp("temp.txt");

    int deleteNo;
    cout << "\nEnter Account Number to be delete: ";
    cin >> deleteNo;

    Account a;
    string separator;
    bool found = false;

    while (file >> a.accountNo >> a.balance >> a.accountType){
        file >> separator;
        getline(file, a.holderName);

        if (a.accountNo == deleteNo){
            found = true;
            continue;
        }
        temp << a.accountNo << " " << a.balance << " " << a.accountType << " |" << a.holderName << "\n";
    }
    file.close();
    temp.close();

    remove("bank.txt");
    rename("temp.txt", "bank.txt");

    if (found){
        cout << "\n[-] Account record permanently closed and deleted.\n";
    } else{
        cout << "\n[-] Target account profile missing.\n";
    }
}
int main(){
    ifstream check("bank.txt");
    if (!check){
        ofstream initial("bank.txt");
        initial << "5001 2500.50 Saving | Tarun Malik\n";
        initial << "5002 89000.00 Current | Tony Stark\n";
        initial << "5003 150.25 Saving | Virat Kohli \n";
        initial.close();
    } else{
        check.close();
    }

    int choice;
    do{
        cout << "\n=============================================";
        cout << "\n             SECURE BANKING PORTAL           ";
        cout << "\n=============================================";
        cout << "\n 1. Open New Account";
        cout << "\n 2. Display All Registers";
        cout << "\n 3. Query Account Details";
        cout << "\n 4. Cash Deposit";
        cout << "\n 5. Cash Withdrawal";
        cout << "\n 6. Close Account Profile";
        cout << "\n 7. Exit ";
        cout << "\n---------------------------------------------";
        cout << "\n Select Action Code (1-7): ";
        cin >> choice;

        switch (choice){
            case 1: createAccount();
                break;
            case 2: displayAllAccounts();
                break;
            case 3: searchAccount(); 
                break;
            case 4: depositWithdraw(1); 
                break;
            case 5: depositWithdraw(2); 
                break;
            case 6: closeAccount(); 
                break;
            case 7: cout << "\n[*] Core services offline. System closed.\n";
                break;
            default: cout << "\n!! Insufficient selection . Retry.\n";
        }
    } while (choice != 7);
    return 0;
}