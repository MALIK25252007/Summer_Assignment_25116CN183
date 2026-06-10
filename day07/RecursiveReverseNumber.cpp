#include <iostream>
using namespace std;
int reverseNumber(int num, int rev = 0){
    if (num == 0)
        return rev;
    rev = rev * 10 + num % 10;
    return reverseNumber(num/10, rev);
}

int main(){
    int number;
    cout << "Enter a number: ";
    cin >> number;
    int reversed = reverseNumber(number);
    cout << "Reversed number: " << reversed << endl;
    return 0;
}