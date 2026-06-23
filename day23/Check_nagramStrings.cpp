#include <iostream>
#include <string>
using namespace std;

int main(){
    string str1, str2;
    cout << "Enter two strings : ";
    cin >> str1 >> str2;
    if (str1.length() != str2.length()){
        cout << "Not anagram" << endl;
        return 0;
    }

    for (int i = 0; i < str1.length(); i++){
        for (int j = 0; j < str1.length() - 1; j++){
            if (str1[j] > str1[j + 1]){
                char temp = str1[j];
                str1[j] = str1[j + 1];
                str1[j + 1] = temp;
            }
            if (str2[j] > str2[j + 1]){
                char temp = str2[j];
                str2[j] = str2[j + 1];
                str2[j + 1] = temp;
            }
        }
    }
    bool isAnagram = true;
    for (int i = 0; i < str1.length(); i++){
        if (str1[i] != str2[i]){
            isAnagram = false;
            break;
        }
    }
    if (isAnagram){
        cout << "Anagram" << endl;
    }else{
        cout << "Not anagram" << endl;
    }

    return 0;
}