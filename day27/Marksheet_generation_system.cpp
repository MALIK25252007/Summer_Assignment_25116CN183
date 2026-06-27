#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Marksheet{
    int rollNo;
    int math;
    int science;
    int english;
    int total;
    double percentage;
    string name;
};

void addRecord(){
    ofstream file("marksheets.txt", ios::app);

    Marksheet m;
    cout << "\nEnter Roll Number: ";
    cin >> m.rollNo;
    cout << "Enter Marks for Math (out of 100): ";
    cin >> m.math;
    cout << "Enter Marks for Science (out of 100): ";
    cin >> m.science;
    cout << "Enter Marks for English (out of 100): ";
    cin >> m.english;
    cin.ignore();
    cout << "Enter Student Name: ";
    getline(cin, m.name);

    m.total = m.math + m.science + m.english;
    m.percentage = m.total / 3.0;

    file << m.rollNo << " " << m.math << " " << m.science << " " << m.english << " " << m.total << " " << m.percentage << " | " << m.name << "\n";
    file.close();
    cout << "\nMarksheet record saved successfully!\n";
}

void viewAllRecords(){
    ifstream file("marksheets.txt");
    if (!file) {
        cout << "\nNo records found!\n";
        return;
    }

    Marksheet m;
    string separator;
    cout << "\nRoll\tMath\tSci\tEng\tTotal\tPer%\tName\n";
    cout << "--------------------------------------------------------\n";

    while (file >> m.rollNo >> m.math >> m.science >> m.english >> m.total >> m.percentage){
        file >> separator;
        getline(file, m.name);
        cout << m.rollNo << "\t" << m.math << "\t" << m.science << "\t" << m.english << "\t" << m.total << "\t" << m.percentage << "%\t" << m.name << "\n";
    }
    file.close();
}

void generateMarksheet(){
    ifstream file("marksheets.txt");
    if (!file) {
        cout << "\nNo records found!\n";
        return;
    }

    int searchRoll;
    cout << "\nEnter Roll Number to generate marksheet: ";
    cin >> searchRoll;

    Marksheet m;
    string separator;
    bool found = false;

    while (file >> m.rollNo >> m.math >> m.science >> m.english >> m.total >> m.percentage){
        file >> separator;
        getline(file, m.name);

        if (m.rollNo == searchRoll){
            cout << "\n======================================";
            cout << "\n          OFFICIAL MARKSHEET          ";
            cout << "\n======================================";
            cout << "\n Roll Number : " << m.rollNo;
            cout << "\n Name        :" << m.name;
            cout << "\n--------------------------------------";
            cout << "\n Subject          Maximum      Obtained";
            cout << "\n--------------------------------------";
            cout << "\n Math             100          " << m.math;
            cout << "\n Science          100          " << m.science;
            cout << "\n English          100          " << m.english;
            cout << "\n--------------------------------------";
            cout << "\n Total Marks : 300            " << m.total;
            cout << "\n Percentage  : " << m.percentage << "%";
            cout << "\n Result      : " << (m.percentage >= 40.0 ? "PASSED" : "FAILED");
            cout << "\n======================================\n";
            found = true;
            break;
        }
    }

    if (!found){
        cout << "\nRecord not found for Roll Number " << searchRoll << "\n";
    }
    file.close();
}

void updateRecord(){
    ifstream file("marksheets.txt");
    ofstream temp("temp.txt");

    int updateRoll;
    cout << "\nEnter Roll Number to update: ";
    cin >> updateRoll;

    Marksheet m;
    string separator;
    bool found = false;

    while (file >> m.rollNo >> m.math >> m.science >> m.english >> m.total >> m.percentage){
        file >> separator;
        getline(file, m.name);

        if (m.rollNo == updateRoll){
            found = true;
            cout << "\nEnter New Marks for Math: ";
            cin >> m.math;
            cout << "Enter New Marks for Science: ";
            cin >> m.science;
            cout << "Enter New Marks for English: ";
            cin >> m.english;
            cin.ignore();
            cout << "Enter New Name: ";
            getline(cin, m.name);

            m.total = m.math + m.science + m.english;
            m.percentage = m.total / 3.0;
            
            m.name = " " + m.name;
        }
        temp << m.rollNo << " " << m.math << " " << m.science << " " << m.english << " " << m.total << " " << m.percentage << " |" << m.name << "\n";
    }

    file.close();
    temp.close();

    remove("marksheets.txt");
    rename("temp.txt", "marksheets.txt");

    if (found){
        cout << "\nRecord updated successfully!\n";
    } else{
        cout << "\nRecord not found.\n";
    }
}

void deleteRecord(){
    ifstream file("marksheets.txt");
    ofstream temp("temp.txt");

    int deleteRoll;
    cout << "\nEnter Roll Number to delete: ";
    cin >> deleteRoll;

    Marksheet m;
    string separator;
    bool found = false;

    while (file >> m.rollNo >> m.math >> m.science >> m.english >> m.total >> m.percentage){
        file >> separator;
        getline(file, m.name);

        if (m.rollNo == deleteRoll){
            found = true;
            continue;
        }
        temp << m.rollNo << " " << m.math << " " << m.science << " " << m.english << " " << m.total << " " << m.percentage << " |" << m.name << "\n";
    }

    file.close();
    temp.close();

    remove("marksheets.txt");
    rename("temp.txt", "marksheets.txt");

    if (found){
        cout << "\nRecord deleted successfully!\n";
    } else{
        cout << "\nRecord not found.\n";
    }
}

int main(){
    ifstream check("marksheets.txt");
    if (!check){
        ofstream initial("marksheets.txt");
        initial << "1 85 90 88 263 87.6667 | Sam Miller\n";
        initial << "2 70 65 80 215 71.6667 | Emma Watson\n";
        initial << "3 45 50 55 150 50 | Alex Carter\n";
        initial.close();
    } else{
        check.close();
    }

    int choice;
    do{
        cout << "\n--- MARKSHEET GENERATION SYSTEM ---\n";
        cout << "1. Add Student Marks\n";
        cout << "2. View All Records\n";
        cout << "3. Generate Marksheet Report\n";
        cout << "4. Update Marks\n";
        cout << "5. Delete Record\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice){
            case 1: addRecord(); break;
            case 2: viewAllRecords(); break;
            case 3: generateMarksheet(); break;
            case 4: updateRecord(); break;
            case 5: deleteRecord(); break;
            case 6: cout << "\nGoodbye!\n"; break;
            default: cout << "\nInvalid choice!\n";
        }
    } while (choice != 6);
    return 0;
}