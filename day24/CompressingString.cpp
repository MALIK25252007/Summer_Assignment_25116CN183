#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cout << "Enter a string :" ;
    cin >> s ;
    string compressed = "";
    int n = s.length();

    for (int i = 0; i < n; i++){
        int count = 1;
        while (i < n - 1 && s[i] == s[i + 1]){
            count++;
            i++;
        }
        compressed += s[i];
        compressed += (char)(count + '0');
    }

    cout << compressed << endl;
    return 0;
}