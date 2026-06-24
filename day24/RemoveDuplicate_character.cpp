#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cout << "Enter a string without spaces :" ;
    cin >> s ;
    string result = "";

    for (int i = 0; i < s.length(); i++){
        bool isDuplicate = false;
        for (int j = 0; j < result.length(); j++){
            if (s[i] == result[j]){
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate){
            result += s[i];
        }
    }

    cout << result << endl;
    return 0;
}