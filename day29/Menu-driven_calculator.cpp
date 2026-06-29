#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void saveToHistory(double num1, char op, double num2, double result){
    ofstream file("history.txt", ios::app);
    if (file){
        file << num1 << " " << op << " " << num2 << " = " << result << "\n";
        file.close();
    }
}
void viewHistory(){
    ifstream file("history.txt");
    if (!file){
        cout << "\n!! No calculation history found.\n";
        return;
    }

    double n1, n2, res;
    char op, eq;
    
    cout << "\n=============================================\n";
    cout << "             CALCULATION HISTORY             \n";
    cout << "=============================================\n";
    
    while (file >> n1 >> op >> n2 >> eq >> res){
        cout << "  " << n1 << " " << op << " " << n2 << " = " << res << "\n";
    }
    
    cout << "=============================================\n";
    file.close();
}
void clearHistory(){
    ofstream file("history.txt", ios::trunc);
    file.close();
    cout << "\n Calculation history cleared successfully!\n";
}

int main(){
    int choice;
    double num1, num2, result;

    do{
        cout << "\n=============================================";
        cout << "\n          SMART MENU CALCULATOR              ";
        cout << "\n=============================================";
        cout << "\n 1. Addition (+)";
        cout << "\n 2. Subtraction (-)";
        cout << "\n 3. Multiplication (*)";
        cout << "\n 4. Division (/)";
        cout << "\n 5. Power (x^y)";
        cout << "\n 6. View Calculation History";
        cout << "\n 7. Clear History File";
        cout << "\n 8. Power Down ";
        cout << "\n---------------------------------------------";
        cout << "\n Select Operation (1-8): ";
        cin >> choice;

        if (choice >= 1 && choice <= 5){
            cout << "Enter first number: ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;
        }

        switch (choice){
            case 1:
                result = num1 + num2;
                cout << "\n[+] Result: " << num1 << " + " << num2 << " = " << result << "\n";
                saveToHistory(num1, '+', num2, result);
                break;
            case 2:
                result = num1 - num2;
                cout << "\n[+] Result: " << num1 << " - " << num2 << " = " << result << "\n";
                saveToHistory(num1, '-', num2, result);
                break;
            case 3:
                result = num1 * num2;
                cout << "\n[+] Result: " << num1 << " * " << num2 << " = " << result << "\n";
                saveToHistory(num1, '*', num2, result);
                break;
            case 4:
                if (num2 != 0){
                    result = num1 / num2;
                    cout << "\n[+] Result: " << num1 << " / " << num2 << " = " << result << "\n";
                    saveToHistory(num1, '/', num2, result);
                } else{
                    cout << "\n!! Error: Division by zero is undefined!\n";
                }
                break;
            case 5:
                result = pow(num1, num2);
                cout << "\n[+] Result: " << num1 << " ^ " << num2 << " = " << result << "\n";
                saveToHistory(num1, '^', num2, result);
                break;
            case 6:
                viewHistory();
                break;
            case 7:
                clearHistory();
                break;
            case 8:
                cout << "\n System terminated. Goodbye!\n";
                break;
            default:
                cout << "\n!! Invalid instruction index. Try again.\n";
        }
    } while (choice != 8);

    return 0;
}