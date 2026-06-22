#include <iostream>
#include <string>
using namespace std;
int main(){
    string str, newString = "";
    cout << "Enter a string: ";
    getline(cin, str);
    for (int i = 0; i < str.length(); i++){
        if (str[i] != ' '){
            newString += str[i];
        }
    }

    cout << "String without spaces: " << newString << endl;
    return 0;
}