//Smart Vending Machine (Automated Refreshment Terminal)
#include <iostream>
#include <string>
using namespace std;
const int MAX_ITEMS = 20;

void bootSystem(int ids[], string names[], double prices[], int stock[], int &itemCount){
    itemCount = 5;

    ids[0] = 11; names[0] = "Campa"; prices[0] = 45.0;  stock[0] = 8;
    ids[1] = 12; names[1] = "Pepsi"; prices[1] = 60.0;  stock[1] = 3;
    ids[2] = 13; names[2] = "Coca-Cola";  prices[2] = 35.0;  stock[2] = 0; 
    ids[3] = 14; names[3] = "Sting";   prices[3] = 25.5;  stock[3] = 12;
    ids[4] = 15; names[4] = "Redbull";   prices[4] = 50.0;  stock[4] = 5;
}

void displayMenu(int ids[], string names[], double prices[], int stock[], int itemCount){
    cout << "\n========================================================================\n";
    cout << "Slot ID\tPrice (INR)\tStock Status\tItem Description\n";
    cout << "========================================================================\n";
    for (int i = 0; i < itemCount; i++){
        cout << "[" << ids[i] << "]\t"
             << "Rs. " << prices[i] << "\t";
        
        if (stock[i] == 0){
            cout << "OUT OF STOCK\t";
        } else {
            cout << stock[i] << " left\t\t";
        }
        
        cout << names[i] << "\n";
    }
    cout << "========================================================================\n";
}

void purchaseItem(int ids[], string names[], double prices[], int stock[], int itemCount){
    int choiceID;
    cout << "\nEnter the Slot ID of the item you want to purchase: ";
    cin >> choiceID;

    int index = -1;
    for (int i = 0; i < itemCount; i++){
        if (ids[i] == choiceID){
            index = i;
            break;
        }
    }

    if (index == -1){
        cout << "\n!! Error: Invalid Slot Code! Please look carefully at the display pad.\n";
        return;
    }

    if (stock[index] <= 0){
        cout << "\n[-] Oh no! '" << names[index] << "' is currently sold out. Try another slot.\n";
        return;
    }

    double userCash;
    cout << " Price is Rs. " << prices[index] << ". Insert currency coins/cash: Rs. ";
    cin >> userCash;

    if (userCash < prices[index]){
        cout << "\n[X] Transaction Denied! Insufficient money. Refunding your Rs. " << userCash << "...\n";
        return;
    }

    stock[index]--;
    double change = userCash - prices[index];

    cout << "\n=============================================\n";
    cout << "          VENDING DISPENSER ACTIVE           \n";
    cout << "=============================================\n";
    cout << " Clink! Drop mechanism triggered...\n";
    cout << " Enjoy your freshly dropped " << names[index] << "!\n";
    
    if (change > 0){
        cout << " Clinking noise... Here is your change: Rs. " << change << "\n";
    }
    cout << "=============================================\n";
}

void searchByName(int ids[], string names[], double prices[], int stock[], int itemCount){
    string searchQuery;
    cout << "\nWhat are you craving today? Enter keyword: ";
    cin.ignore();
    getline(cin, searchQuery);

    bool found = false;
    cout << "\n--- Matching Results From Machine Vault ---\n";
    for (int i = 0; i < itemCount; i++){
        if (names[i].find(searchQuery) != string::npos){
            cout << " -> Slot [" << ids[i] << "] " << names[i] << " | Cost: Rs. " << prices[i] << " | Stock: " << stock[i] << "\n";
            found = true;
        }
    }

    if (!found){
        cout << " No items found matching '" << searchQuery << "' in our vendor inventory rows.\n";
    }
}

void RestockMachine(int ids[], string names[], double prices[], int stock[], int itemCount){
    int targetID, newStock;
    cout << "\n[SECURE ACCESS] Enter item Slot ID to restock: ";
    cin >> targetID;

    for (int i = 0; i < itemCount; i++){
        if (ids[i] == targetID){
            cout << "Current stock of '" << names[i] << "' is " << stock[i] << ". Enter added units: ";
            cin >> newStock;
            stock[i] += newStock;
            cout << "\n Supply locked! New inventory depth for " << names[i] << " is now " << stock[i] << " units.\n";
            return;
        }
    }
    cout << "\n Error: That item key does not exist inside this firmware database.\n";
}

int main(){
    int itemIDs[MAX_ITEMS];
    string itemNames[MAX_ITEMS];
    double itemPrices[MAX_ITEMS];
    int itemStock[MAX_ITEMS];
    int currentItemCount = 0;

    bootSystem(itemIDs, itemNames, itemPrices, itemStock, currentItemCount);

    int operationalChoice;
    do{
        cout << "\n=============================================";
        cout << "\n       NEON DRIP-FEED VENDING TERMINAL       ";
        cout << "\n=============================================";
        cout << "\n 1. Look Inside Machine (Display Menu)";
        cout << "\n 2. Insert Cash & Dispense Item (Purchase)";
        cout << "\n 3. Query Machine Sensors (Search Item)";
        cout << "\n 4. Service Maintenance (Restock Items)";
        cout << "\n 5. Shutdown Machine Interface";
        cout << "\n---------------------------------------------";
        cout << "\n Press Physical Button (1-5): ";
        cin >> operationalChoice;

        switch (operationalChoice){
            case 1: displayMenu(itemIDs, itemNames, itemPrices, itemStock, currentItemCount); break;
            case 2: purchaseItem(itemIDs, itemNames, itemPrices, itemStock, currentItemCount); break;
            case 3: searchByName(itemIDs, itemNames, itemPrices, itemStock, currentItemCount); break;
            case 4: RestockMachine(itemIDs, itemNames, itemPrices, itemStock, currentItemCount); break;
            case 5: cout << "\n system end. Goodbye!\n"; break;
            default: cout << "\n!! Error. Invalid keypress combination. Please hit buttons 1 to 5.\n";
        }
    } while (operationalChoice != 5);

    return 0;
}