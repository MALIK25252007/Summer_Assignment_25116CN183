#include <iostream>
using namespace std;
unsigned long long Factorial(int n){
    unsigned long long factorial = 1;

    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }
    return factorial;
}
int main(){
    int num;
    cout << "Enter a positive integer (0 to 20): ";
    cin >> num;
    if (num > 20){
        cout << "The number is too large!!!!!." << endl;
    }else{
        cout << "Factorial of " << num << " is: " << Factorial(num) << endl;
    }

    return 0;
}