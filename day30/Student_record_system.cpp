#include <iostream>
#include <string>
using namespace std;

int main(){
    const int MAX_STUDENTS = 50;
    int rollNumbers[MAX_STUDENTS];
    string studentNames[MAX_STUDENTS];
    string studentCourses[MAX_STUDENTS];
    double studentGPAs[MAX_STUDENTS];
    int currentCount = 3;
    
    rollNumbers[0] = 101; studentNames[0] = "Rahul Sharma"; studentCourses[0] = "B.Tech CSE"; studentGPAs[0] = 8.5;
    rollNumbers[1] = 102; studentNames[1] = "Priya Patel";  studentCourses[1] = "B.Tech CSIT"; studentGPAs[1] = 9.1;
    rollNumbers[2] = 103; studentNames[2] = "Amit Kumar";   studentCourses[2] = "B.Tech CSDS";  studentGPAs[2] = 7.4;

    int choice;
    do{
        cout << "\n=============================================";
        cout << "\n           STUDENT RECORD SYSTEM             ";
        cout << "\n=============================================";
        cout << "\n 1. Add New Student Record";
        cout << "\n 2. Display All Student Records";
        cout << "\n 3. Search Student by Roll Number";
        cout << "\n 4. Update Student GPA";
        cout << "\n 5. Delete Student Record";
        cout << "\n 6. Exit System";
        cout << "\n---------------------------------------------";
        cout << "\n Select Option Index (1-6): ";
        cin >> choice;

        switch (choice){
            case 1:{
                if (currentCount >= MAX_STUDENTS){
                    cout << "\n!! Error: System Database Full! Cannot add more records.\n";
                    break;
                }
                
                cout << "\n=============================================\n";
                cout << "             ADD NEW STUDENT RECORD          \n";
                cout << "=============================================\n";
                cout << " Enter Roll Number: ";
                cin >> rollNumbers[currentCount];
                cin.ignore();
                cout << " Enter Student Name: ";
                getline(cin, studentNames[currentCount]);
                cout << " Enter Course Name: ";
                getline(cin, studentCourses[currentCount]);
                cout << " Enter GPA: ";
                cin >> studentGPAs[currentCount];

                currentCount++;
                cout << "\n Student profile added successfully!\n";
                break;
            }
            case 2:{
                if (currentCount == 0){
                    cout << "\n!! System Database is empty.\n";
                    break;
                }
                cout << "\n========================================================================\n";
                cout << "Roll No\tGPA\tCourse\t\t\tStudent Name\n";
                cout << "========================================================================\n";
                for (int i = 0; i < currentCount; i++){
                    cout << rollNumbers[i] << "\t"
                         << studentGPAs[i] << "\t"
                         << studentCourses[i] << "\t\t"
                         << studentNames[i] << "\n";
                }
                cout << "========================================================================\n";
                break;
            }
            case 3:{
                int searchRoll;
                cout << "\nEnter Roll Number to search: ";
                cin >> searchRoll;

                bool found = false;
                for (int i = 0; i < currentCount; i++){
                    if (rollNumbers[i] == searchRoll){
                        cout << "\n############################################################";
                        cout << "\n#                 STUDENT RECORD CARD                      #";
                        cout << "\n############################################################";
                        cout << "\n  ROLL NUMBER : " << rollNumbers[i];
                        cout << "\n  NAME        : " << studentNames[i];
                        cout << "\n  COURSE      : " << studentCourses[i];
                        cout << "\n  CURRENT GPA : " << studentGPAs[i];
                        cout << "\n############################################################\n";
                        found = true;
                        break;
                    }
                }
                if (!found){
                    cout << "\n[-] Student Record with Roll Number " << searchRoll << " not found.\n";
                }
                break;
            }
            case 4:{
                int updateRoll;
                cout << "\nEnter Roll Number to update GPA: ";
                cin >> updateRoll;

                bool found = false;
                for (int i = 0; i < currentCount; i++){
                    if (rollNumbers[i] == updateRoll){
                        cout << "\n Current GPA for " << studentNames[i] << " is: " << studentGPAs[i];
                        cout << "\n Enter New GPA: ";
                        cin >> studentGPAs[i];
                        cout << "\n GPA updated successfully!\n";
                        found = true;
                        break;
                    }
                }
                if (!found){
                    cout << "\n Student Record with Roll Number " << updateRoll << " not found.\n";
                }
                break;
            }
            case 5:{
                int deleteRoll;
                cout << "\nEnter Roll Number to delete record: ";
                cin >> deleteRoll;

                int indexToDelete = -1;
                for (int i = 0; i < currentCount; i++){
                    if (rollNumbers[i] == deleteRoll){
                        indexToDelete = i;
                        break;
                    }
                }

                if (indexToDelete != -1){
                    for (int i = indexToDelete; i < currentCount - 1; i++){
                        rollNumbers[i] = rollNumbers[i + 1];
                        studentNames[i] = studentNames[i + 1];
                        studentCourses[i] = studentCourses[i + 1];
                        studentGPAs[i] = studentGPAs[i + 1];
                    }
                    currentCount--;
                    cout << "\n Student record deleted successfully!\n";
                } else{
                    cout << "\n Student Record with Roll Number " << deleteRoll << " not found.\n";
                }
                break;
            }
            case 6:
                cout << "\n Program terminated successfully. Goodbye!\n";
                break;
            default:
                cout << "\n!! Invalid input choice. Please select 1-6.\n";
        }
    } while (choice != 6);

    return 0;
}