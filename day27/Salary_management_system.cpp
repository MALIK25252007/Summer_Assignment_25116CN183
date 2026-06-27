#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct SalaryRecord{
    int empId;
    double baseSalary;
    double bonus;
    double deductions;
    double netPay;
};

void addSalary(){
    ofstream file("salary.txt", ios::app);

    SalaryRecord s;
    cout << "\nEnter Employee ID: ";
    cin >> s.empId;
    cout << "Enter Base Salary: ";
    cin >> s.baseSalary;
    cout << "Enter Bonus: ";
    cin >> s.bonus;
    cout << "Enter Deductions: ";
    cin >> s.deductions;

    s.netPay = s.baseSalary + s.bonus - s.deductions;

    file << s.empId << " " << s.baseSalary << " " << s.bonus << " " << s.deductions << " " << s.netPay << "\n";
    file.close();
    cout << "\nSalary record added successfully!\n";
}

void viewAllSalaries(){
    ifstream file("salary.txt");
    if (!file){
        cout << "\nNo records found!\n";
        return;
    }

    SalaryRecord s;
    cout << "\nEmp ID\tBase\tBonus\tDeduct.\tNet Pay\n";
    cout << "-----------------------------------------------\n";

    while (file >> s.empId >> s.baseSalary >> s.bonus >> s.deductions >> s.netPay){
        cout << s.empId << "\t" << s.baseSalary << "\t" << s.bonus << "\t" << s.deductions << "\t" << s.netPay << "\n";
    }
    file.close();
}

void searchSalary(){
    ifstream file("salary.txt");
    if (!file){
        cout << "\nNo records found!\n";
        return;
    }

    int searchId;
    cout << "\nEnter Employee ID to search salary: ";
    cin >> searchId;

    SalaryRecord s;
    bool found = false;

    while (file >> s.empId >> s.baseSalary >> s.bonus >> s.deductions >> s.netPay) {
        if (s.empId == searchId) {
            cout << "\n--- Salary Details ---";
            cout << "\nEmployee ID: " << s.empId;
            cout << "\nBase Salary: " << s.baseSalary;
            cout << "\nBonus      : " << s.bonus;
            cout << "\nDeductions : " << s.deductions;
            cout << "\nNet Pay    : " << s.netPay << "\n";
            found = true;
            break;
        }
    }

    if (!found){
        cout << "\nSalary record not found for this ID.\n";
    }
    file.close();
}

void updateSalary(){
    ifstream file("salary.txt");
    ofstream temp("temp.txt");

    int updateId;
    cout << "\nEnter Employee ID to update salary: ";
    cin >> updateId;

    SalaryRecord s;
    bool found = false;

    while (file >> s.empId >> s.baseSalary >> s.bonus >> s.deductions >> s.netPay){
        if (s.empId == updateId){
            found = true;
            cout << "\nEnter New Base Salary: ";
            cin >> s.baseSalary;
            cout << "Enter New Bonus: ";
            cin >> s.bonus;
            cout << "Enter New Deductions: ";
            cin >> s.deductions;

            s.netPay = s.baseSalary + s.bonus - s.deductions;
        }
        temp << s.empId << " " << s.baseSalary << " " << s.bonus << " " << s.deductions << " " << s.netPay << "\n";
    }

    file.close();
    temp.close();

    remove("salary.txt");
    rename("temp.txt", "salary.txt");

    if (found){
        cout << "\nSalary record updated successfully!\n";
    } else{
        cout << "\nRecord not found.\n";
    }
}

void deleteSalary(){
    ifstream file("salary.txt");
    ofstream temp("temp.txt");

    int deleteId;
    cout << "\nEnter Employee ID to delete salary record: ";
    cin >> deleteId;

    SalaryRecord s;
    bool found = false;

    while (file >> s.empId >> s.baseSalary >> s.bonus >> s.deductions >> s.netPay){
        if (s.empId == deleteId){
            found = true;
            continue;
        }
        temp << s.empId << " " << s.baseSalary << " " << s.bonus << " " << s.deductions << " " << s.netPay << "\n";
    }

    file.close();
    temp.close();

    remove("salary.txt");
    rename("temp.txt", "salary.txt");

    if (found){
        cout << "\nSalary record deleted successfully!\n";
    } else{
        cout << "\nRecord not found.\n";
    }
}

int main(){
    ifstream check("salary.txt");
    if (!check){
        ofstream initial("salary.txt");
        initial << "101 50000 5000 2000 53000\n";
        initial << "102 60000 7000 2500 64500\n";
        initial << "103 45000 3000 1500 46500\n";
        initial.close();
    } else{
        check.close();
    }

    int choice;
    do{
        cout << "\n--- SALARY SYSTEM ---\n";
        cout << "1. Add Salary Record\n";
        cout << "2. View All Records\n";
        cout << "3. Search Salary\n";
        cout << "4. Update Salary\n";
        cout << "5. Delete Record\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice){
            case 1: addSalary(); break;
            case 2: viewAllSalaries(); break;
            case 3: searchSalary(); break;
            case 4: updateSalary(); break;
            case 5: deleteSalary(); break;
            case 6: cout << "\nGoodbye!\n"; break;
            default: cout << "\nInvalid choice!\n";
        }
    } while (choice != 6);
    return 0;
}