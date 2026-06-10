#include <iostream>
using namespace std;

int fact(int digit){
    unsigned long long factorial = 1;
    for (int i = 1; i <= digit; i++) {

        factorial *= i;
    }
    return factorial;
}
int main(){
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    int sum = 0;
    int temp = n;
    while(temp > 0){
        int digit = temp % 10;
        sum += fact(digit);
        temp /= 10;
    }
    if(sum == n){
        cout << n << " is a strong number." << endl;
    }
    else{
        cout << n << " is not a strong number." << endl;
    }
    return 0;
}