#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Employee{
    int id;
    string name;
    string designation;
    double salary;
    int age;
};
void addEmployee(){
    ofstream file("employees.txt", ios::app);
    
    Employee e;
    cout << "\nEnter Employee ID: ";
    cin >> e.id;
    cin.ignore();
    cout << "Enter Age: ";
    cin >> e.age;
    cout << "Enter Salary: ";
    cin >> e.salary;
    cin.ignore();
    cout << "Enter Designation: ";
    getline(cin, e.designation);
    cout << "Enter Full Name: ";
    getline(cin, e.name);

    file << e.id << " " << e.age << " " << e.salary << " " << e.designation << " | " << e.name << "\n";
    file.close();
    cout << "\nEmployee record added successfully!\n";
}

void viewAllEmployees(){
    ifstream file("employees.txt");
    if (!file) {
        cout << "\nNo records found!\n";
        return;
    }

    Employee e;
    cout << "\nID\tAge\tSalary\tDesignation\tName\n";
    cout << "--------------------------------------------------------\n";

    while (file >> e.id >> e.age >> e.salary){
        file >> e.designation;
        string separator;
        file >> separator; 
        getline(file, e.name); 

        cout << e.id << "\t" << e.age << "\t" << e.salary << "\t" << e.designation << "\t" << e.name << "\n";
    }
    file.close();
}

void searchEmployee(){
    ifstream file("employees.txt");
    if (!file){
        cout << "\nNo records found!\n";
        return;
    }

    int searchId;
    cout << "\nEnter Employee ID to search: ";
    cin >> searchId;

    Employee e;
    bool found = false;

    while (file >> e.id >> e.age >> e.salary){
        file >> e.designation;
        string separator;
        file >> separator;
        getline(file, e.name);

        if (e.id == searchId){
            cout << "\nRecord Found!";
            cout << "\nID: " << e.id;
            cout << "\nName: " << e.name;
            cout << "\nAge: " << e.age;
            cout << "\nDesignation: " << e.designation;
            cout << "\nSalary: " << e.salary << "\n";
            found = true;
            break;
        }
    }

    if (!found){
        cout << "\nEmployee not found.\n";
    }
    file.close();
}

void updateEmployee(){
    ifstream file("employees.txt");
    ofstream temp("temp.txt");

    int updateId;
    cout << "\nEnter Employee ID to update: ";
    cin >> updateId;

    Employee e;
    bool found = false;

    while (file >> e.id >> e.age >> e.salary){
        file >> e.designation;
        string separator;
        file >> separator;
        getline(file, e.name);

        if (e.id == updateId){
            found = true;
            cout << "\nEnter New Age: ";
            cin >> e.age;
            cout << "Enter New Salary: ";
            cin >> e.salary;
            cin.ignore();
            cout << "Enter New Designation: ";
            getline(cin, e.designation);
            cout << "Enter New Name: ";
            getline(cin, e.name);
            
            e.name = " " + e.name;
        }
        temp << e.id << " " << e.age << " " << e.salary << " " << e.designation << " |" << e.name << "\n";
    }

    file.close();
    temp.close();

    remove("employees.txt");
    rename("temp.txt", "employees.txt");

    if (found){
        cout << "\nRecord updated successfully!\n";
    } else{
        cout << "\nRecord not found.\n";
    }
}

void deleteEmployee(){
    ifstream file("employees.txt");
    ofstream temp("temp.txt");

    int deleteId;
    cout << "\nEnter Employee ID to delete: ";
    cin >> deleteId;

    Employee e;
    bool found = false;

    while (file >> e.id >> e.age >> e.salary){
        file >> e.designation;
        string separator;
        file >> separator;
        getline(file, e.name);

        if (e.id == deleteId){
            found = true;
            continue; 
        }
        temp << e.id << " " << e.age << " " << e.salary << " " << e.designation << " |" << e.name << "\n";
    }

    file.close();
    temp.close();

    remove("employees.txt");
    rename("temp.txt", "employees.txt");

    if (found){
        cout << "\nRecord deleted successfully!\n";
    } else{
        cout << "\nRecord not found.\n";
    }
}

int main(){
    ifstream check("employees.txt");
    if (!check){
        ofstream initial("employees.txt");
        initial << "101 28 55000 Manager | Elon musk\n";
        initial << "102 32 65000 Developer | Narendra Modi\n";
        initial << "103 24 40000 Designer | Khan Sir\n";
        initial.close();
    } else{
        check.close();
    }

    int choice;
    do{
        cout << "\n--- EMPLOYEE MANAGEMENT SYSTEM ---\n";
        cout << "1. Add Employee\n";
        cout << "2. View All\n";
        cout << "3. Search\n";
        cout << "4. Update\n";
        cout << "5. Delete\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice){
            case 1: addEmployee(); break;
            case 2: viewAllEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: updateEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: cout << "\nGoodbye!\n"; break;
            default: cout << "\nInvalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}