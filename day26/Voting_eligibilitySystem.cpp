#include <iostream>
#include <string>
using namespace std;

int main(){
    string name;
    int age = 0;
    char citizenStatus;

    cout << "========================================" << endl;
    cout << "      WELCOME TO THE VOTER PORTAL       " << endl;
    cout << "========================================" << endl;

    cout << "Please enter your name: ";
    getline(cin, name);

    cout << "Enter your age: ";
    cin >> age;

    cout << "Are you a registered citizen? (y/n): ";
    cin >> citizenStatus;

    cout << "\n--- Processing Verification ---" << endl;

    if (age >= 18 && (citizenStatus == 'y' || citizenStatus == 'Y')){
        cout << "Status: APPROVED" << endl;
        cout << "Congratulations " << name << ", you are eligible to vote!" << endl;
        cout << "Be ready for next election your vote desides this country future." << endl;
    } else if (age < 18 && (citizenStatus == 'y' || citizenStatus == 'Y')){
        cout << "Status: DENIED" << endl;
        cout << "Sorry " << name << ", you are too young to vote." << endl;
        cout << "You will be eligible in " << 18 - age << " year(s)." << endl;
    } else{
        cout << "Status: INELIGIBLE" << endl;
        cout << "Sorry " << name << ", you must be a registered citizen to vote." << endl;
    }

    cout << "========================================" << endl;
    return 0;
}