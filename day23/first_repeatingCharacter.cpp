#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    cout << "Enter a string without spaces : ";
    cin >> str;
    char result = '\0';

    for (int i = 0; i < str.length(); i++){
        for (int j = 0; j < i; j++){
            if (str[i] == str[j]){
                result = str[i];
                break;
            }
        }
        if (result != '\0'){
            break;
        }
    }
    if (result != '\0'){
        cout << "first repeating character is :" << result << endl;
    }else{
        cout << "No repeating character found" << endl;
    }

    return 0;
}