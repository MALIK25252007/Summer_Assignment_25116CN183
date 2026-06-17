#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int rev = 0, temp = n;
    while (n > 0){
        rev = rev * 10 + n % 10; 
        n /= 10;
    }
    if (temp == rev){
        cout << temp << " is a palindrome number." << endl;
    }
    else{
        cout << temp << " is not a palindrome number." << endl;
    }
    return 0;
}