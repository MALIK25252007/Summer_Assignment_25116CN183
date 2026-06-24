#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cout << "Enter a string with multiple words :" ;
    cin >> s ;
    string longest = "";
    string current = "";
    for (int i = 0; i < s.length(); i++){
        if (s[i] != ' '){
            current += s[i];
        } else{
            if (current.length() > longest.length()){
                longest = current;
            }
            current = "";
        }
    }

    if (current.length() > longest.length()){
        longest = current;
    }

    cout << longest << endl;
    return 0;
}