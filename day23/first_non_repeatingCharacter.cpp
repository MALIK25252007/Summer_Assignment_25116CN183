#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    cout << "Enter a string : ";
    cin >> str;

    char result = '\0';

    for (int i = 0; i < str.length(); i++){
        bool isRepeating = false;
        for (int j = 0; j < str.length(); j++){
            if (i != j && str[i] == str[j]){
                isRepeating = true;
                break;
            }
        }
        if (!isRepeating){
            result = str[i];
            break;
        }
    }

    if (result != '\0'){
        cout << "First non repeating character is :" << result << endl;
    }else{
        cout << "No non-repeating character found" << endl;
    }

    return 0;
}