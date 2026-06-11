#include <iostream>
using namespace std;
int Sum(int a, int b){
    return a + b;
}
int main(){
    int num1, num2, sum;
    cout << "This is a function to calculate sum. " << endl;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    
    sum = Sum(num1, num2);
    cout << "The sum of " << num1 << " and " << num2 << " is: " << sum << endl;

    return 0;
}