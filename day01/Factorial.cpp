#include <iostream>
using namespace std;
int main(){
    
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    unsigned long long factorial = 1;
    for (int i = 1; i <= n; ++i) {

        factorial *= i;
    }
    cout << "The factorial of " << n << " is: " << factorial << endl;
    return 0;
}