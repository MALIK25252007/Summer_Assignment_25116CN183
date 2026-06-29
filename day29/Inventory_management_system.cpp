#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Product{
    int id;
    int stock;
    double price;
    string category;
    string name;
};

void addProduct(){
    ofstream file("inventory.txt", ios::app);

    Product p;
    cout << "\n=============================================\n";
    cout << "             ADD NEW PRODUCT ENTRY           \n";
    cout << "=============================================\n";
    cout << " Enter Product ID: ";
    cin >> p.id;
    cout << " Enter Stock Quantity: ";
    cin >> p.stock;
    cout << " Enter Unit Price (₹): ";
    cin >> p.price;
    cout << " Enter Category (Single_Word): ";
    cin >> p.category;
    cin.ignore();
    cout << " Enter Product Name: ";
    getline(cin, p.name);

    file << p.id << " " << p.stock << " " << p.price << " " << p.category << " | " << p.name << "\n";
    file.close();
    cout << "\n[+] Product successfully logged to inventory!\n";
}

void displayInventory(){
    ifstream file("inventory.txt");
    if (!file){
        cout << "\n!! No active inventory database found!\n";
        return;
    }

    Product p;
    string separator;
    cout << "\n========================================================================\n";
    cout << "ID\tStock\tPrice\tCategory\tProduct Name\n";
    cout << "========================================================================\n";

    while (file >> p.id >> p.stock >> p.price >> p.category){
        file >> separator;
        getline(file, p.name);
        cout << p.id << "\t" 
             << p.stock << "\t$" 
             << p.price << "\t" 
             << p.category << "\t\t" 
             << p.name << "\n";
    }
    file.close();
    cout << "========================================================================\n";
}

void checkLowStock(){
    ifstream file("inventory.txt");
    if (!file){
        cout << "\n!! Inventory database not found!\n";
        return;
    }

    Product p;
    string separator;
    bool found = false;

    cout << "\n============================================================\n";
    cout << "             LOW STOCK REORDER ALERTS (< 10 ITEMS)          \n";
    cout << "============================================================\n";

    while (file >> p.id >> p.stock >> p.price >> p.category){
        file >> separator;
        getline(file, p.name);

        if (p.stock < 10){
            cout << " -> [ALERT] ID: " << p.id << " | Name:" << p.name << " | Remaining Stock: " << p.stock << "\n";
            found = true;
        }
    }

    if (!found){
        cout << "  All items are adequately stocked above threshold levels.\n";
    }
    cout << "============================================================\n";
    file.close();
}

void updateProduct(){
    ifstream file("inventory.txt");
    ofstream temp("temp.txt");

    int updateId;
    cout << "\nEnter Product ID to update specifications: ";
    cin >> updateId;

    Product p;
    string separator;
    bool found = false;

    while (file >> p.id >> p.stock >> p.price >> p.category){
        file >> separator;
        getline(file, p.name);

        if (p.id == updateId) {
            found = true;
            cout << "\n!! Stock Item Located! Input modified variables:\n";
            cout << " New Stock Quantity: ";
            cin >> p.stock;
            cout << " New Unit Price (₹): ";
            cin >> p.price;
            cout << " New Category Tag: ";
            cin >> p.category;
            cin.ignore();
            cout << " -> Enter New Product Name: ";
            getline(cin, p.name);
            
            p.name = " " + p.name;
        }
        temp << p.id << " " << p.stock << " " << p.price << " " << p.category << " |" << p.name << "\n";
    }

    file.close();
    temp.close();

    remove("inventory.txt");
    rename("temp.txt", "inventory.txt");

    if (found){
        cout << "\n[+] Inventory logs updated successfully!\n";
    } else{
        cout << "\n[-] Stock master reference ID missing.\n";
    }
}

void deleteProduct(){
    ifstream file("inventory.txt");
    ofstream temp("temp.txt");

    int deleteId;
    cout << "\nEnter Product ID to delete: ";
    cin >> deleteId;

    Product p;
    string separator;
    bool found = false;

    while (file >> p.id >> p.stock >> p.price >> p.category){
        file >> separator;
        getline(file, p.name);

        if (p.id == deleteId){
            found = true;
            continue;
        }
        temp << p.id << " " << p.stock << " " << p.price << " " << p.category << " |" << p.name << "\n";
    }
    file.close();
    temp.close();

    remove("inventory.txt");
    rename("temp.txt", "inventory.txt");

    if (found){
        cout << "\n Product successfully dropped from stock records.\n";
    } else{
        cout << "\n Stock master reference ID missing.\n";
    }
}

int main(){
    ifstream check("inventory.txt");
    if (!check){
        ofstream initial("inventory.txt");
        initial << "101 45 1200.00 Electronics | iPhone_15\n";
        initial << "102 4 15.50 Stationary | Notebook_Pack\n";
        initial << "103 75 8.99 Groceries | Organic_Almonds\n";
        initial.close();
    } else{
        check.close();
    }

    int choice;
    do{
        cout << "\n=============================================";
        cout << "\n         WAREHOUSE INVENTORY TERMINAL        ";
        cout << "\n=============================================";
        cout << "\n 1. Register New Product Record";
        cout << "\n 2. Display Stock Sheet";
        cout << "\n 3. Scan for Low Stock Thresholds";
        cout << "\n 4. Modify Existing Product File";
        cout << "\n 5. Remove Product from Registry";
        cout << "\n 6. Terminate Connection Protocol";
        cout << "\n---------------------------------------------";
        cout << "\n Chose one Parameter (1-6): ";
        cin >> choice;

        switch (choice){
            case 1: addProduct();
               break; 
            case 2: displayInventory();
               break;
            case 3: checkLowStock();
               break;
            case 4: updateProduct();
               break;
            case 5: deleteProduct();
               break;
            case 6: cout << "\nSystems offline. Session closed safely.\n";
               break;
            default: cout << "\n!! Operation mismatched. Re-select.\n";
        }
    } while (choice != 6);

    return 0;
}