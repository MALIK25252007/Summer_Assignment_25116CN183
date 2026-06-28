#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Ticket{
    int pnr;
    int trainNo;
    int age;
    double fare;
    string trainName;
    string quota;
    string passengerName;
};

void bookTicket(){
    ofstream file("railway.txt", ios::app);

    Ticket t;
    cout << "\n=============================================\n";
    cout << "          IRCTC TICKET BOOKING SYSTEM        \n";
    cout << "=============================================\n";
    cout << " -> Enter PNR Number (5 Digits): ";
    cin >> t.pnr;
    cout << " -> Enter 5-Digit Train Number: ";
    cin >> t.trainNo;
    cout << " -> Enter Passenger Age: ";
    cin >> t.age;
    cout << " -> Enter Ticket Fare (INR): ";
    cin >> t.fare;
    cout << " -> Enter Quota (General/Tatkal/Ladies): ";
    cin >> t.quota;
    cin.ignore();
    cout << " -> Enter Train Name (Use_Underscores): ";
    cin >> t.trainName;
    cin.ignore();
    cout << " -> Enter Passenger Full Name: ";
    getline(cin, t.passengerName);

    file << t.pnr << " " << t.trainNo << " " << t.age << " " << t.fare << " " << t.quota << " " << t.trainName << " | " << t.passengerName << "\n";
    file.close();
    cout << "\n[+] Ticket Booked Successfully! PNR Generated.\n";
}

void viewAllReservations(){
    ifstream file("railway.txt");
    if (!file) {
        cout << "\n[!] No reservation records found!\n";
        return;
    }

    Ticket t;
    string separator;
    cout << "\n=================================================================================\n";
    cout << "PNR\tTrain No\tAge\tFare\tQuota\tTrain Name\tPassenger Name\n";
    cout << "=================================================================================\n";

    while (file >> t.pnr >> t.trainNo >> t.age >> t.fare >> t.quota >> t.trainName){
        file >> separator;
        getline(file, t.passengerName);
        cout << t.pnr << "\t" 
             << t.trainNo << "\t\t" 
             << t.age << "\t" 
             << t.fare << "\t" 
             << t.quota << "\t"
             << t.trainName << "\t" 
             << t.passengerName << "\n";
    }
    file.close();
    cout << "=================================================================================\n";
}

void printETicket(){
    ifstream file("railway.txt");
    if (!file){
        cout << "\n[!] No database records discovered!\n";
        return;
    }

    int searchPnr;
    cout << "\nEnter 5-Digit PNR Number to print Electronic Ticket: ";
    cin >> searchPnr;

    Ticket t;
    string separator;
    bool found = false;

    while (file >> t.pnr >> t.trainNo >> t.age >> t.fare >> t.quota >> t.trainName){
        file >> separator;
        getline(file, t.passengerName);

        if (t.pnr == searchPnr){
            cout << "\n############################################################";
            cout << "\n#                INDIAN RAILWAYS E-TICKET                  #";
            cout << "\n#                    IRCTC NEXT GENERATION                 #";
            cout << "\n############################################################";
            cout << "\n  PNR NUMBER  : " << t.pnr << "             QUOTA: " << t.quota;
            cout << "\n  TRAIN NO    : " << t.trainNo << "             TRAIN: " << t.trainName;
            cout << "\n------------------------------------------------------------";
            cout << "\n  PASSENGER NAME              AGE         STATUS";
            cout << "\n------------------------------------------------------------";
            cout << "\n " << t.passengerName;
            cout << "\t\t      " << t.age << "          CNF (CONFIRMED)";
            cout << "\n------------------------------------------------------------";
            cout << "\n  TOTAL FARE  : Rs. " << t.fare;
            cout << "\n  IRCTC JOURNEY STATUS: HAPPY JOURNEY / SHUBH YATRA!";
            cout << "\n############################################################\n";
            found = true;
            break;
        }
    }

    if (!found){
        cout << "\n[-] PNR Mismatch. Record not active .\n";
    }
    file.close();
}

void updateReservation(){
    ifstream file("railway.txt");
    ofstream temp("temp.txt");

    int updatePnr;
    cout << "\nEnter PNR Number to modify details: ";
    cin >> updatePnr;

    Ticket t;
    string separator;
    bool found = false;

    while (file >> t.pnr >> t.trainNo >> t.age >> t.fare >> t.quota >> t.trainName){
        file >> separator;
        getline(file, t.passengerName);

        if (t.pnr == updatePnr) {
            found = true;
            cout << "\n[!] PNR Located! Input updated passenger details:\n";
            cout << " -> New Train Number: ";
            cin >> t.trainNo;
            cout << " -> New Passenger Age: ";
            cin >> t.age;
            cout << " -> New Ticket Fare: ";
            cin >> t.fare;
            cout << " -> New Quota Type: ";
            cin >> t.quota;
            cout << " -> New Train Name (Use_Underscores): ";
            cin >> t.trainName;
            cin.ignore();
            cout << " -> New Passenger Name: ";
            getline(cin, t.passengerName);
            
            t.passengerName = " " + t.passengerName;
        }
        temp << t.pnr << " " << t.trainNo << " " << t.age << " " << t.fare << " " << t.quota << " " << t.trainName << " |" << t.passengerName << "\n";
    }

    file.close();
    temp.close();

    remove("railway.txt");
    rename("temp.txt", "railway.txt");

    if (found){
        cout << "\n[+] Charts updated successfully!\n";
    } else{
        cout << "\n[-] Target PNR ledger missing.\n";
    }
}

void cancelTicket(){
    ifstream file("railway.txt");
    ofstream temp("temp.txt");

    int cancelPnr;
    cout << "\nEnter PNR Number to cancel reservation: ";
    cin >> cancelPnr;

    Ticket t;
    string separator;
    bool found = false;

    while (file >> t.pnr >> t.trainNo >> t.age >> t.fare >> t.quota >> t.trainName){
        file >> separator;
        getline(file, t.passengerName);

        if (t.pnr == cancelPnr){
            found = true;
            continue;
        }
        temp << t.pnr << " " << t.trainNo << " " << t.age << " " << t.fare << " " << t.quota << " " << t.trainName << " |" << t.passengerName << "\n";
    }

    file.close();
    temp.close();

    remove("railway.txt");
    rename("temp.txt", "railway.txt");

    if (found){
        cout << "\n[-] Ticket successfully cancelled. Refund processed to source.\n";
    }else{
        cout << "\n[-] Target PNR ledger missing.\n";
    }
}

int main(){
    ifstream check("railway.txt");
    if (!check){
        ofstream initial("railway.txt");
        initial << "43211 12002 34 1250.00 Tatkal Shatabdi_Exp | Raja\n";
        initial << "55672 12952 62 2450.00 General Rajdhani_Exp | Dev\n";
        initial << "10923 22691 21 850.00 Ladies Gomati_Exp | Dollor\n";
        initial.close();
    } else{
        check.close();
    }

    int choice;
    do{
        cout << "\n=============================================";
        cout << "\n          INDIAN RAILWAY RESERVATION         ";
        cout << "\n=============================================";
        cout << "\n 1. Book Train Ticket (Counter/Quota)";
        cout << "\n 2. View Central Chart Registry";
        cout << "\n 3. Print Official IRCTC E-Ticket";
        cout << "\n 4. Modify Ticket Credentials";
        cout << "\n 5. Cancel Ticket Reservation";
        cout << "\n 6. Exit Passenger Terminal";
        cout << "\n---------------------------------------------";
        cout << "\n Select Option (1-6): ";
        cin >> choice;

        switch (choice){
            case 1: bookTicket(); break;
            case 2: viewAllReservations(); break;
            case 3: printETicket(); break;
            case 4: updateReservation(); break;
            case 5: cancelTicket(); break;
            case 6: cout << "\n[*] Core servers updating. Logging off safely.\n"; break;
            default: cout << "\n[!] Option unrecognized. Please run selection again.\n";
        }
    } while (choice != 6);

    return 0;
}