#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Contact{
    int serialNo;
    string phoneNo;
    string email;
    string storageType;
    string name;
};

void addContact(){
    ofstream file("contacts.txt", ios::app);

    Contact c;
    int storageChoice;

    cout << "\n=============================================\n";
    cout << "             CREATE NEW CONTACT              \n";
    cout << "=============================================\n";
    cout << " -> Enter Serial Number/ID: ";
    cin >> c.serialNo;
    cout << " -> Enter Phone Number: ";
    cin >> c.phoneNo;
    cout << " -> Enter Email Address: ";
    cin >> c.email;
    
    cout << "\n Select Storage Destination:\n";
    cout << " 1. SIM Card 1\n";
    cout << " 2. SIM Card 2\n";
    cout << " 3. Local Phone Storage\n";
    cout << " 4. Cloud Account Sync\n";
    cout << " Choose Option (1-4): ";
    cin >> storageChoice;

    switch (storageChoice){
        case 1: c.storageType = "SIM_1"; break;
        case 2: c.storageType = "SIM_2"; break;
        case 3: c.storageType = "Internal"; break;
        case 4: c.storageType = "Cloud_Sync"; break;
        default: c.storageType = "Internal";
    }

    cin.ignore();
    cout << " -> Enter Contact Name: ";
    getline(cin, c.name);

    file << c.serialNo << " " << c.phoneNo << " " << c.email << " " << c.storageType << " | " << c.name << "\n";
    file.close();
    cout << "\n[+] Contact saved successfully to " << c.storageType << "!\n";
}

void viewAllContacts(){
    ifstream file("contacts.txt");
    if (!file){
        cout << "\n[!] Address book file is empty!\n";
        return;
    }

    Contact c;
    string separator;
    cout << "\n=================================================================================\n";
    cout << "ID\tPhone No\tStorage\t\tEmail\t\t\tName\n";
    cout << "=================================================================================\n";

    while (file >> c.serialNo >> c.phoneNo >> c.email >> c.storageType){
        file >> separator;
        getline(file, c.name);
        cout << c.serialNo << "\t" 
             << c.phoneNo << "\t" 
             << c.storageType << "\t"
             << c.email << "\t\t" 
             << c.name << "\n";
    }
    file.close();
    cout << "=================================================================================\n";
}

void searchContact(){
    ifstream file("contacts.txt");
    if (!file){
        cout << "\n!! Address book data missing!\n";
        return;
    }

    string searchName;
    cin.ignore();
    cout << "\nEnter Name to search: ";
    getline(cin, searchName);

    Contact c;
    string separator;
    bool found = false;

    while (file >> c.serialNo >> c.phoneNo >> c.email >> c.storageType){
        file >> separator;
        getline(file, c.name);

        string cleanName = c.name;
        if (!cleanName.empty() && cleanName[0] == ' '){
            cleanName = cleanName.substr(1);
        }

        if (cleanName == searchName){
            if (c.storageType == "BLACKLISTED"){
                cout << "\n[X] WARNING: This contact is currently on your BLACKLIST! [X]\n";
            }
            cout << "\n############################################################";
            cout << "\n#                 CONTACT CARD DETAILS                     #";
            cout << "\n############################################################";
            cout << "\n  NAME         : " << cleanName;
            cout << "\n  PHONE NUMBER : " << c.phoneNo;
            cout << "\n  EMAIL        : " << c.email;
            cout << "\n  STORAGE LOC  : " << c.storageType;
            cout << "\n  RECORD ID    : " << c.serialNo;
            cout << "\n############################################################\n";
            found = true;
            break;
        }
    }

    if (!found){
        cout << "\n[-] Name mismatch. Contact not found.\n";
    }
    file.close();
}

void blacklistContact(){
    ifstream file("contacts.txt");
    ofstream temp("temp.txt");
    if (!file){
        cout << "\n!! Address book file missing!\n";
        return;
    }

    int targetId;
    cout << "\nEnter Contact ID to Blacklist : ";
    cin >> targetId;

    Contact c;
    string separator;
    bool found = false;

    while (file >> c.serialNo >> c.phoneNo >> c.email >> c.storageType){
        file >> separator;
        getline(file, c.name);

        if (c.serialNo == targetId){
            found = true;
            c.storageType = "BLACKLISTED";
        }
        temp << c.serialNo << " " << c.phoneNo << " " << c.email << " " << c.storageType << " |" << c.name << "\n";
    }

    file.close();
    temp.close();

    remove("contacts.txt");
    rename("temp.txt", "contacts.txt");

    if (found){
        cout << "\n[X] Contact has been securely moved to the Blacklist database!\n";
    } else{
        cout << "\n[-] Target ID entry missing.\n";
    }
}

void updateContact(){
    ifstream file("contacts.txt");
    ofstream temp("temp.txt");

    int updateId;
    cout << "\nEnter Contact ID to modify: ";
    cin >> updateId;

    Contact c;
    string separator;
    bool found = false;
    int storageChoice;

    while (file >> c.serialNo >> c.phoneNo >> c.email >> c.storageType){
        file >> separator;
        getline(file, c.name);

        if (c.serialNo == updateId) {
            found = true;
            cout << "\n[!] Profile Located! Input updated details:\n";
            cout << " -> New Phone Number: ";
            cin >> c.phoneNo;
            cout << " -> New Email Address: ";
            cin >> c.email;
            
            cout << "\n Select New Storage Location:\n";
            cout << " 1. SIM Card 1\n";
            cout << " 2. SIM Card 2\n";
            cout << " 3. Local Phone Storage\n";
            cout << " 4. Cloud Account Sync\n";
            cout << " Choose Option (1-4): ";
            cin >> storageChoice;

            switch (storageChoice){
                case 1: c.storageType = "SIM_1"; 
                    break;
                case 2: c.storageType = "SIM_2";
                    break;
                case 3: c.storageType = "Internal"; 
                    break;
                case 4: c.storageType = "Cloud_Sync"; 
                    break;
                default: c.storageType = "Internal";
            }

            cin.ignore();
            cout << " -> New Contact Name: ";
            getline(cin, c.name);
            
            c.name = " " + c.name;
        }
        temp << c.serialNo << " " << c.phoneNo << " " << c.email << " " << c.storageType << " |" << c.name << "\n";
    }

    file.close();
    temp.close();

    remove("contacts.txt");
    rename("temp.txt", "contacts.txt");

    if (found){
        cout << "\n[+] Contact updated successfully!\n";
    } else{
        cout << "\n[-] Target ID entry missing.\n";
    }
}

void deleteContact(){
    ifstream file("contacts.txt");
    ofstream temp("temp.txt");

    int deleteId;
    cout << "\nEnter Contact ID to delete: ";
    cin >> deleteId;

    Contact c;
    string separator;
    bool found = false;

    while (file >> c.serialNo >> c.phoneNo >> c.email >> c.storageType){
        file >> separator;
        getline(file, c.name);

        if (c.serialNo == deleteId){
            found = true;
            continue;
        }
        temp << c.serialNo << " " << c.phoneNo << " " << c.email << " " << c.storageType << " |" << c.name << "\n";
    }

    file.close();
    temp.close();

    remove("contacts.txt");
    rename("temp.txt", "contacts.txt");

    if (found){
        cout << "\n[-] Contact entry erased from memory allocation.\n";
    } else{
        cout << "\n[-] Target ID entry missing.\n";
    }
}

int main(){
    ifstream check("contacts.txt");
    if (!check){
        ofstream initial("contacts.txt");
        initial << "1 9876543210 rahul@gmail.com Cloud_Sync | Rahul Sharma\n";
        initial << "2 8887776665 priya@yahoo.com SIM_1 | Priya Patel\n";
        initial << "3 9111222333 amit@outlook.com BLACKLISTED | Amit Kumar\n";
        initial.close();
    } else{
        check.close();
    }


    int choice;
    do{
        cout << "\n=============================================";
        cout << "\n            SMART PHONE CONTACT BOOK         ";
        cout << "\n=============================================";
        cout << "\n 1. Create New Contact Profile";
        cout << "\n 2. Display Saved Phone Directory";
        cout << "\n 3. Find Contact by Full Name";
        cout << "\n 4. Add Contact to Blacklist";
        cout << "\n 5. Edit Contact Credentials";
        cout << "\n 6. Erase Contact Profile";
        cout << "\n 7. Lock Phone Interface";
        cout << "\n---------------------------------------------";
        cout << "\n Select Dial Command (1-7): ";
        cin >> choice;

        switch (choice){
            case 1: addContact(); break;
            case 2: viewAllContacts(); break;
            case 3: searchContact(); break;
            case 4: blacklistContact(); break;
            case 5: updateContact(); break;
            case 6: deleteContact(); break;
            case 7: cout << "\n[*] Session ended. Device Locked.\n"; break;
            default: cout << "\n[!] Execution instruction invalid. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}