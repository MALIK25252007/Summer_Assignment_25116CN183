#include <iostream>
using namespace std;
bool isPalindrome(int num){
    int originalNum = num;
    int reversedNum = 0;
    int remainder;
    if (num < 0){
        return false;
    }
    while (num > 0){
        remainder = num % 10;
        reversedNum = (reversedNum * 10) + remainder;
        num = num / 10;
    }
    return originalNum == reversedNum;
}

int main(){
    int number;
    cout << "Enter an integer: ";
    cin >> number;
    if (isPalindrome(number)){
        cout << number << " is a palindrome." << endl;
    }else{
        cout << number << " is not a palindrome." << endl;
    }
    return 0;
}