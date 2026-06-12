#include <iostream>
using namespace std;
bool isArmstrong(int num){
    int originalNum = num;
    int temp = num;
    int digitCount = 0;
    int sum = 0;
    while (temp > 0) {
        digitCount++;
        temp = temp / 10;
    }

    temp = num; 
    while (temp > 0){
        int remainder = temp % 10;
        int power = 1;
        for (int i = 0; i < digitCount; i++) {
            power *=  remainder;
        }
        
        sum = sum + power;
        temp = temp / 10;
    }
    return sum == originalNum;
}

int main(){
    int number;
    cout << "Enter an integer: ";
    cin >> number;
    if (isArmstrong(number)){
        cout << number << " is an Armstrong number." << endl;
    }else{
        cout << number << " is not an Armstrong number." << endl;
    }

    return 0;
}