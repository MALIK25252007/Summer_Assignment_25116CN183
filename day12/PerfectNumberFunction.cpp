#include <iostream>
using namespace std;
bool isPerfect(int num){
    if (num <= 0) {
        return false;
    }
    int sum = 0;
    for (int i = 1; i < num; i++){
        if (num % i == 0) {
            sum = sum + i;
        }
    }
    return sum == num;
}
int main(){
    int number;
    cout << "Enter an integer: ";
    cin >> number;

    if (isPerfect(number)){
        cout << number << " is a perfect number." << endl;
    }else{
        cout << number << " is not a perfect number." << endl;
    }
    return 0;
}    