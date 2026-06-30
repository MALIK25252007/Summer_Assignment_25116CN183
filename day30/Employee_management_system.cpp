#include <iostream>
#include <string>
using namespace std;

int main(){
    const int MAX_EMPLOYEES = 40;

    int employeeIDs[MAX_EMPLOYEES];
    string employeeNames[MAX_EMPLOYEES];
    string departments[MAX_EMPLOYEES];
    double salaries[MAX_EMPLOYEES];
    int currentCount = 3;

    employeeIDs[0] = 201; employeeNames[0] = "Rohan Sharma";   departments[0] = "IT_Services";  salaries[0] = 45000.0;
    employeeIDs[1] = 202; employeeNames[1] = "Sneha Verma";    departments[1] = "HR_Operations";salaries[1] = 38000.0;
    employeeIDs[2] = 203; employeeNames[2] = "Vikram Singh";   departments[2] = "Finance";      salaries[2] = 52000.0;

    int choice;
    do{
        cout << "\n=============================================";
        cout << "\n          EMPLOYEE MANAGEMENT SYSTEM         ";
        cout << "\n=============================================";
        cout << "\n 1. Register New Employee Profile";
        cout << "\n 2. Display Employees Data";
        cout << "\n 3. Search Employee by Profile ID";
        cout << "\n 4. Modify Salary";
        cout << "\n 5. Terminate Employee Record";
        cout << "\n 6. Log Out of Management";
        cout << "\n---------------------------------------------";
        cout << "\n Select Console Action (1-6): ";
        cin >> choice;

        switch (choice){
            case 1:{
                if (currentCount >= MAX_EMPLOYEES){
                    cout << "\n!! Error: System Database Full! Cannot add more rows.\n";
                    break;
                }

                cout << "\n=============================================\n";
                cout << "         REGISTER NEW EMPLOYEE PROFILE       \n";
                cout << "=============================================\n";
                cout << " Enter Employee ID: ";
                cin >> employeeIDs[currentCount];
                cin.ignore();
                cout << " Enter Employee Full Name: ";
                getline(cin, employeeNames[currentCount]);
                cout << " Enter Department (Single_Word): ";
                getline(cin, departments[currentCount]);
                cout << " Enter Monthly Salary (INR): ";
                cin >> salaries[currentCount];

                currentCount++;
                cout << "\n Employee record initialized successfully!\n";
                break;
            }
            case 2: {
                if (currentCount == 0){
                    cout << "\n!! Corporate registry ledger is empty.\n";
                    break;
                }
                cout << "\n========================================================================\n";
                cout << "ID\tSalary (INR)\tDepartment\t\tEmployee Name\n";
                cout << "========================================================================\n";
                for (int i = 0; i < currentCount; i++){
                    cout << employeeIDs[i] << "\t"
                         << salaries[i] << "\t\t"
                         << departments[i] << "\t\t"
                         << employeeNames[i] << "\n";
                }
                cout << "========================================================================\n";
                break;
            }
            case 3:{
                int searchID;
                cout << "\nEnter Employee ID to look up: ";
                cin >> searchID;

                bool found = false;
                for (int i = 0; i < currentCount; i++){
                    if (employeeIDs[i] == searchID){
                        cout << "\n############################################################";
                        cout << "\n#               OFFICIAL EMPLOYEE PROFILE                  #";
                        cout << "\n############################################################";
                        cout << "\n  EMPLOYEE ID   : " << employeeIDs[i];
                        cout << "\n  FULL NAME     : " << employeeNames[i];
                        cout << "\n  DEPARTMENT    : " << departments[i];
                        cout << "\n  BASE SALARY   : Rs. " << salaries[i];
                        cout << "\n############################################################\n";
                        found = true;
                        break;
                    }
                }
                if (!found){
                    cout << "\n Error: ID mismatch. No matching employee file found.\n";
                }
                break;
            }
            case 4:{
                int updateID;
                cout << "\nEnter Employee ID to modify salary parameters: ";
                cin >> updateID;

                bool found = false;
                for (int i = 0; i < currentCount; i++){
                    if (employeeIDs[i] == updateID){
                        cout << "\n Current salary allocation for " << employeeNames[i] << " is: " << salaries[i];
                        cout << "\n Enter New Base Salary: ";
                        cin >> salaries[i];
                        cout << "\n Financial ledger updated successfully!\n";
                        found = true;
                        break;
                    }
                }
                if (!found){
                    cout << "\n Error: ID mismatch. No matching employee file found.\n";
                }
                break;
            }
            case 5:{
                int deleteID;
                cout << "\nEnter Employee ID to remove profile: ";
                cin >> deleteID;

                int indexToDelete = -1;
                for (int i = 0; i < currentCount; i++){
                    if (employeeIDs[i] == deleteID){
                        indexToDelete = i;
                        break;
                    }
                }

                if (indexToDelete != -1){
                    for (int i = indexToDelete; i < currentCount - 1; i++){
                        employeeIDs[i] = employeeIDs[i + 1];
                        employeeNames[i] = employeeNames[i + 1];
                        departments[i] = departments[i + 1];
                        salaries[i] = salaries[i + 1];
                    }
                    currentCount--;
                    cout << "\n Employee records purged from central filesystem.\n";
                } else{
                    cout << "\n Error: ID mismatch. No matching employee file found.\n";
                }
                break;
            }
            case 6:
                cout << "\n Database encryption locked. System secure. Goodbye!\n";
                break;
            default:
                cout << "\n!! Operation syntax unverified. Choose parameters from 1-6.\n";
        }
    } while (choice != 6);

    return 0;
}