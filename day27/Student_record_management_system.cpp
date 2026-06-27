#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student{
    int id;
    string name;
    int age;
    string course;
    double gpa;
};

void addStudent(){
    ofstream file("students.txt", ios::app);
    
    Student s;
    cout << "\nEnter Student ID: ";
    cin >> s.id;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, s.name);
    cout << "Enter Age: ";
    cin >> s.age;
    cin.ignore();
    cout << "Enter Course: ";
    getline(cin, s.course);
    cout << "Enter GPA: ";
    cin >> s.gpa;

    file << s.id << " " << s.age << " " << s.gpa << " " << s.course << " | " << s.name << "\n";
    file.close();
    cout << "\nStudent added successfully!\n";
}

void viewAllStudents(){
    ifstream file("students.txt");
    if (!file){
        cout << "\nNo records found!\n";
        return;
    }

    Student s;
    cout << "\nID\tAge\tGPA\tCourse\t\tName\n";
    cout << "------------------------------------------------\n";

    while (file >> s.id >> s.age >> s.gpa){
        file >> s.course;
        string separator;
        file >> separator; 
        getline(file, s.name); 

        cout << s.id << "\t" << s.age << "\t" << s.gpa << "\t" << s.course << "\t" << s.name << "\n";
    }
    file.close();
}

void searchStudent(){
    ifstream file("students.txt");
    if (!file){
        cout << "\nNo records found!\n";
        return;
    }

    int searchId;
    cout << "\nEnter ID to search: ";
    cin >> searchId;

    Student s;
    bool found = false;

    while (file >> s.id >> s.age >> s.gpa){
        file >> s.course;
        string separator;
        file >> separator;
        getline(file, s.name);

        if (s.id == searchId){
            cout << "\nRecord Found!";
            cout << "\nID: " << s.id;
            cout << "\nName: " << s.name;
            cout << "\nAge: " << s.age;
            cout << "\nCourse: " << s.course;
            cout << "\nGPA: " << s.gpa << "\n";
            found = true;
            break;
        }
    }

    if (!found){
        cout << "\nStudent not found.\n";
    }
    file.close();
}

void updateStudent(){
    ifstream file("students.txt");
    ofstream temp("temp.txt");

    int updateId;
    cout << "\nEnter ID to update: ";
    cin >> updateId;

    Student s;
    bool found = false;

    while (file >> s.id >> s.age >> s.gpa){
        file >> s.course;
        string separator;
        file >> separator;
        getline(file, s.name);

        if (s.id == updateId){
            found = true;
            cout << "\nEnter New Name: ";
            cin.ignore();
            getline(cin, s.name);
            cout << "Enter New Age: ";
            cin >> s.age;
            cout << "Enter New Course: ";
            cin >> s.course;
            cout << "Enter New GPA: ";
            cin >> s.gpa;
            
            s.name = " " + s.name;
        }
        temp << s.id << " " << s.age << " " << s.gpa << " " << s.course << " |" << s.name << "\n";
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found){
        cout << "\nRecord updated successfully!\n";
    } else{
        cout << "\nRecord not found.\n";
    }
}

void deleteStudent(){
    ifstream file("students.txt");
    ofstream temp("temp.txt");

    int deleteId;
    cout << "\nEnter ID to delete: ";
    cin >> deleteId;

    Student s;
    bool found = false;

    while (file >> s.id >> s.age >> s.gpa){
        file >> s.course;
        string separator;
        file >> separator;
        getline(file, s.name);

        if (s.id == deleteId){
            found = true;
            continue; 
        }
        temp << s.id << " " << s.age << " " << s.gpa << " " << s.course << " |" << s.name << "\n";
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found){
        cout << "\nRecord deleted successfully!\n";
    } else{
        cout << "\nRecord not found.\n";
    }
}

int main(){
    ifstream check("students.txt");
    if (!check){
        ofstream initial("students.txt");
        initial << "101 20 3.8 CS | Alice Smith\n";
        initial << "102 21 3.5 Math | Bob Jones\n";
        initial << "103 19 3.9 IT | Charlie Brown\n";
        initial.close();
    } else{
        check.close();
    }

    int choice;
    do{
        cout << "\n--- STUDENT MANAGEMENT SYSTEM ---\n";
        cout << "1. Add Student\n";
        cout << "2. View All\n";
        cout << "3. Search\n";
        cout << "4. Update\n";
        cout << "5. Delete\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice){
            case 1: addStudent(); 
                 break;
            case 2: viewAllStudents(); 
                  break;
            case 3: searchStudent(); 
                  break;
            case 4: updateStudent();
                   break;
            case 5: deleteStudent(); 
                   break;
            case 6: cout << "\nGoodbye!\n";
                   break;
            default: cout << "\nInvalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}