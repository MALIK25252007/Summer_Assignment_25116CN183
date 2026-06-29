#include <iostream>
#include <string>
using namespace std;

int main(){
    int choice;
    string str1, str2, result;

    do{
        cout << "\n=============================================";
        cout << "\n          STRING OPERATIONS SYSTEM           ";
        cout << "\n=============================================";
        cout << "\n 1. Find Length of a String";
        cout << "\n 2. Reverse a String";
        cout << "\n 3. Join Two Strings ";
        cout << "\n 4. Compare Two Strings";
        cout << "\n 5. Convert String to Uppercase";
        cout << "\n 6. Exit System";
        cout << "\n---------------------------------------------";
        cout << "\n Select Operation (1-6): ";
        cin >> choice;
        cin.ignore(); 

        switch (choice){
            case 1:
                cout << "\nEnter a string: ";
                getline(cin, str1);
                cout << "\nLength of the string: " << str1.length() << " characters\n";
                break;

            case 2:
                cout << "\nEnter a string to reverse: ";
                getline(cin, str1);
                result = "";
                for (int i = str1.length() - 1; i >= 0; i--){
                    result += str1[i];
                }
                cout << "\n[+] Reversed String: " << result << "\n";
                break;

            case 3:
                cout << "\Enter First String: ";
                getline(cin, str1);
                cout << "Enter Second String: ";
                getline(cin, str2);
                result = str1 + str2;
                cout << "\n[+] Concatenated String: " << result << "\n";
                break;

            case 4:
                cout << "\nEnter First String to compare: ";
                getline(cin, str1);
                cout << "Enter Second String to compare: ";
                getline(cin, str2);
                if (str1 == str2){
                    cout << "\n[==] Both strings are perfectly identical.\n";
                } else if (str1 > str2){
                    cout << "\n[>] First string is greater than the second string.\n";
                } else{
                    cout << "\n[<] Second string is greater than the first string.\n";
                }
                break;

            case 5:
                cout << "\nEnter a string in lowercase: ";
                getline(cin, str1);
                for (int i = 0; i < str1.length(); i++){
                    if (str1[i] >= 'a' && str1[i] <= 'z'){
                        str1[i] = str1[i] - 32; 
                    }
                }
                cout << "\nUppercase String: " << str1 << "\n";
                break;

            case 6:
                cout << "\nSystem offline. Session closed safely.\n";
                break;

            default:
                cout << "\n!! Operation selection invalid. Please choose 1-6.\n";
        }
    } while (choice != 6);

    return 0;
}