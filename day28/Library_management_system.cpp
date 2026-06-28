#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Book{
    int id;
    int copies;
    double price;
    string category;
    string title;
};

void addBook(){
    ofstream file("library.txt", ios::app);

    Book b;
    cout << "\n=============================================\n";
    cout << "             ADD NEW BOOK ENTRY              \n";
    cout << "=============================================\n";
    cout << " -> Enter Book ID: ";
    cin >> b.id;
    cout << " -> Available Copies: ";
    cin >> b.copies;
    cout << " -> Price (₹): ";
    cin >> b.price;
    cin.ignore();
    cout << " -> Category: ";
    cin >> b.category;
    cin.ignore();
    cout << " -> Enter Book Title: ";
    getline(cin, b.title);

    file << b.id << " " << b.copies << " " << b.price << " " << b.category << " | " << b.title << "\n";
    file.close();
    cout << "\n[+] Book successfully added in database !\n";
}

void viewAllBooks(){
    ifstream file("library.txt");
    if (!file){
        cout << "\n[!] No active registry found!\n";
        return;
    }

    Book b;
    string separator;
    cout << "\n========================================================================\n";
    cout << "ID\tCopies\tPrice\tCategory\tBook Title\n";
    cout << "========================================================================\n";

    while (file >> b.id >> b.copies >> b.price >> b.category){
        file >> separator;
        getline(file, b.title);
        cout << b.id << "\t" 
             << b.copies << "\t$" 
             << b.price << "\t" 
             << b.category << "\t\t" 
             << b.title << "\n";
    }
    file.close();
    cout << "========================================================================\n";
}

void searchBook(){
    ifstream file("library.txt");
    if (!file){
        cout << "\n[!] No active registry found!\n";
        return;
    }

    int searchId;
    cout << "\nEnter Book ID to look up: ";
    cin >> searchId;

    Book b;
    string separator;
    bool found = false;

    while (file >> b.id >> b.copies >> b.price >> b.category){
        file >> separator;
        getline(file, b.title);

        if (b.id == searchId){
            cout << "\n############################################################";
            cout << "\n#                 BOOK INFORMATION DETAILS                 #";
            cout << "\n############################################################";
            cout << "\n  BOOK ID      : " << b.id;
            cout << "\n  TITLE           :" << b.title;
            cout << "\n  GENRE/CATEGORY  : " << b.category;
            cout << "\n  COPIES IN STOCK : " << b.copies;
            cout << "\n  UNIT VALUE      : $" << b.price;
            cout << "\n  AVAILABILITY    : " << (b.copies > 0 ? "IN STOCK" : "OUT OF STOCK");
            cout << "\n############################################################\n";
            found = true;
            break;
        }
    }

    if (!found){
        cout << "\n[-] System mismatch. Target Book ID not cataloged.\n";
    }
    file.close();
}

void updateBook(){
    ifstream file("library.txt");
    ofstream temp("temp.txt");

    int updateId;
    cout << "\nEnter Book ID to update details: ";
    cin >> updateId;

    Book b;
    string separator;
    bool found = false;

    while (file >> b.id >> b.copies >> b.price >> b.category){
        file >> separator;
        getline(file, b.title);

        if (b.id == updateId){
            found = true;
            cout << "\n[!] Index Record Located! Input modified data specifications:\n";
            cout << " -> New Copy Count: ";
            cin >> b.copies;
            cout << " -> New Unit Price: ";
            cin >> b.price;
            cout << " -> New Category: ";
            cin >> b.category;
            cin.ignore();
            cout << " -> New Book Title: ";
            getline(cin, b.title);
            
            b.title = " " + b.title;
        }
        temp << b.id << " " << b.copies << " " << b.price << " " << b.category << " |" << b.title << "\n";
    }

    file.close();
    temp.close();

    remove("library.txt");
    rename("temp.txt", "library.txt");

    if (found){
        cout << "\n[+] book index updated securely!\n";
    } else{
        cout << "\n[-] Target book profile missing.\n";
    }
}

void deleteBook(){
    ifstream file("library.txt");
    ofstream temp("temp.txt");

    int deleteId;
    cout << "\nEnter Book ID to expunge from shelves: ";
    cin >> deleteId;

    Book b;
    string separator;
    bool found = false;

    while (file >> b.id >> b.copies >> b.price >> b.category){
        file >> separator;
        getline(file, b.title);

        if (b.id == deleteId){
            found = true;
            continue;
        }
        temp << b.id << " " << b.copies << " " << b.price << " " << b.category << " |" << b.title << "\n";
    }

    file.close();
    temp.close();

    remove("library.txt");
    rename("temp.txt", "library.txt");

    if (found){
        cout << "\n[-] Book data permanently purged from indexing.\n";
    } else{
        cout << "\n[-] Target book profile missing.\n";
    }
}

int main(){
    ifstream check("library.txt");
    if (!check){
        ofstream initial("library.txt");
        initial << "1001 5 14.99 Comics | Avenges Endgame\n";
        initial << "1002 2 24.50 Science | Mission Mangal\n";
        initial << "1003 0 11.25 Action | Bahubali\n";
        initial.close();
    } else{
        check.close();
    }

    int choice;
    do{
        cout << "\n=============================================";
        cout << "\n          LIBRARY MANAGEMENT TERMINAL        ";
        cout << "\n=============================================";
        cout << "\n 1. Register New Book";
        cout << "\n 2. Display Catalog Directory";
        cout << "\n 3. Query Book by ID";
        cout << "\n 4. Modify Book Entry";
        cout << "\n 5. Remove Book File";
        cout << "\n 6. Terminate Connection";
        cout << "\n---------------------------------------------";
        cout << "\n Direct Call Option (1-6): ";
        cin >> choice;

        switch (choice){
            case 1: addBook(); break;
            case 2: viewAllBooks(); break;
            case 3: searchBook(); break;
            case 4: updateBook(); break;
            case 5: deleteBook(); break;
            case 6: cout << "\n[*] Database offline. Session closed safely.\n"; break;
            default: cout << "\n!! Operation parameter incorrect. Retry.\n";
        }
    } while (choice != 6);

    return 0;
}