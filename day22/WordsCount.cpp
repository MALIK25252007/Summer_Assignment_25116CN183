#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    int words = 0;

    cout << "Enter a sentence: ";
    getline(cin, str);
    if (str.length() > 0){
        words = words + 1;
    }
    for (int i = 0; i < str.length(); i++){
        if (str[i] == ' '){
            words++;
        }
    }
    cout << "Total number of words: " << words << endl;
    return 0;
}