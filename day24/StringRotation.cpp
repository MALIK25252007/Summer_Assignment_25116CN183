#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1, s2;
    cout << "Enter two strings :" ;
    cin >> s1 >> s2;

    if (s1.length() != s2.length()){
        cout << "false" << endl;
        return 0;
    }

    string temp = s1 + s1;

    if (temp.find(s2) < temp.length()){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }

    return 0;
}