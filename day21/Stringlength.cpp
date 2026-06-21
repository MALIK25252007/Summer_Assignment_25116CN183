#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    int length = 0;

    cout << "Enter a string: ";
    getline(cin, str);

    while (str[length] != '\0'){
        length++;
    }
    cout << "Length of the string is: " << length << endl;

    return 0;
}