#include <iostream>
using namespace std;
int sumOfDigits(int n){
    if (n == 0){
        return 0;
    }
    return (n % 10) + sumOfDigits(n / 10);
}

int main(){
    int num;
    cout << "Enter an integer: ";
    cin >> num; 
    int positiveNum = num;
    if (positiveNum < 0){
        positiveNum = -positiveNum;
    }
    cout << "The sum of digits of " << num << " is " << sumOfDigits(positiveNum) << endl; 
    return 0;
}