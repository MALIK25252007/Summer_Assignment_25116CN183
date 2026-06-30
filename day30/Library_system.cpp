#include <iostream>
#include <string>
using namespace std;

int main(){
    const int MAX_BOOKS = 30;
    int bookIDs[MAX_BOOKS];
    string bookTitles[MAX_BOOKS];
    string bookAuthors[MAX_BOOKS];
    string issueStatus[MAX_BOOKS];
    int currentCount = 3;

    bookIDs[0] = 1001; bookTitles[0] = "Runway";   bookAuthors[0] = "Ranveer Malya"; issueStatus[0] = "Available";
    bookIDs[1] = 1002; bookTitles[1] = "Kingdom"; bookAuthors[1] = "Tarun Malik";          issueStatus[1] = "Issued";
    bookIDs[2] = 1003; bookTitles[2] = "1984";               bookAuthors[2] = "Vijay Thalapathi";       issueStatus[2] = "Available";

    int choice;
    do{
        cout << "\n=============================================";
        cout << "\n             MINI LIBRARY SYSTEM             ";
        cout << "\n=============================================";
        cout << "\n 1. Add New Book Entry";
        cout << "\n 2. Display Entire database";
        cout << "\n 3. Search Book by unique ID";
        cout << "\n 4. Update Book Issue Status";
        cout << "\n 5. Remove Book";
        cout << "\n 6. Shutdown Terminal Session";
        cout << "\n---------------------------------------------";
        cout << "\n Select Action Index (1-6): ";
        cin >> choice;

        switch (choice){
            case 1:{
                if (currentCount >= MAX_BOOKS){
                    cout << "\n!!Error: Library Catalog is full! Cannot add more rows.\n";
                    break;
                }

                cout << "\n=============================================\n";
                cout << "             ADD NEW BOOK ENTRY              \n";
                cout << "=============================================\n";
                cout << " Enter Book ID number: ";
                cin >> bookIDs[currentCount];
                cin.ignore();
                cout << " Enter Book Title: ";
                getline(cin, bookTitles[currentCount]);
                cout << " Enter Author Name: ";
                getline(cin, bookAuthors[currentCount]);
                issueStatus[currentCount] = "Available";

                currentCount++;
                cout << "\n Book successfully indexed into the catalog!\n";
                break;
            }
            case 2: {
                if (currentCount == 0){
                    cout << "\n!! Library directory is empty.\n";
                    break;
                }
                cout << "\n=================================================================================\n";
                cout << "ID\tStatus\t\tAuthor\t\t\tTitle\n";
                cout << "=================================================================================\n";
                for (int i = 0; i < currentCount; i++){
                    cout << bookIDs[i] << "\t"
                         << issueStatus[i] << "\t\t"
                         << bookAuthors[i] << "\t\t"
                         << bookTitles[i] << "\n";
                }
                cout << "=================================================================================\n";
                break;
            }
            case 3:{
                int searchID;
                cout << "\nEnter Book ID to look up: ";
                cin >> searchID;

                bool found = false;
                for (int i = 0; i < currentCount; i++){
                    if (bookIDs[i] == searchID){
                        cout << "\n############################################################";
                        cout << "\n#                 BOOK INDEX PROFILE CARD                  #";
                        cout << "\n############################################################";
                        cout << "\n  CATALOG ID   : " << bookIDs[i];
                        cout << "\n  TITLE        : " << bookTitles[i];
                        cout << "\n  AUTHOR       : " << bookAuthors[i];
                        cout << "\n  AVAILABILITY : " << issueStatus[i];
                        cout << "\n############################################################\n";
                        found = true;
                        break;
                    }
                }
                if (!found){
                    cout << "\n System error: Target book ID matching failed.\n";
                }
                break;
            }
            case 4:{
                int updateID;
                cout << "\nEnter Book ID to change inventory status: ";
                cin >> updateID;

                bool found = false;
                for (int i = 0; i < currentCount; i++){
                    if (bookIDs[i] == updateID){
                        int statusChoice;
                        cout << "\n Current status for '" << bookTitles[i] << "' is: " << issueStatus[i];
                        cout << "\n Select new status:\n 1. Available\n 2. Issued\n Choice: ";
                        cin >> statusChoice;

                        if (statusChoice == 1) issueStatus[i] = "Available";
                        else if (statusChoice == 2) issueStatus[i] = "Issued";
                        
                        cout << "\n Status modified successfully!\n";
                        found = true;
                        break;
                    }
                }
                if (!found){
                    cout << "\n System error: Target book ID matching failed.\n";
                }
                break;
            }
            case 5:{
                int deleteID;
                cout << "\nEnter Book ID to remove from inventory: ";
                cin >> deleteID;

                int indexToDelete = -1;
                for (int i = 0; i < currentCount; i++){
                    if (bookIDs[i] == deleteID){
                        indexToDelete = i;
                        break;
                    }
                }

                if (indexToDelete != -1){
                    for (int i = indexToDelete; i < currentCount - 1; i++){
                        bookIDs[i] = bookIDs[i + 1];
                        bookTitles[i] = bookTitles[i + 1];
                        bookAuthors[i] = bookAuthors[i + 1];
                        issueStatus[i] = issueStatus[i + 1];
                    }
                    currentCount--;
                    cout << "\n Record permanently deleted.\n";
                } else{
                    cout << "\n System error: Target book ID matching failed.\n";
                }
                break;
            }
            case 6:
                cout << "\n Database offline. Goodbye!\n";
                break;
            default:
                cout << "\n!! Selected execution is unknown. Retry.\n";
        }
    } while (choice != 6);

    return 0;
}