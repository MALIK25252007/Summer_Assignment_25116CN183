#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    int vowels = 0;
    int consonants = 0;
    cout << "Enter a string: ";
    getline(cin, str);

    for (int i = 0; i < str.length(); i++){
        char ch = str[i];

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||  ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
            vowels++;
        }
        else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
            consonants++;
        }
    }

    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
    return 0;
}