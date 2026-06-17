#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter the term number (n) to find the nth Fibonacci term: ";
    cin >> n;
    if (n < 0){
        cout << "Please enter a non-negative integer." << endl;
        return 1;
    }
    unsigned long long a = 0, b = 1, nthTerm;
    if (n == 0){
        nthTerm = a;
    } else if (n == 1){
        nthTerm = b;
    }else{
        for (int i = 2; i <= n; ++i) {
            nthTerm = a + b;
            a = b;
            b = nthTerm;
        }
    }
    cout << "The " << n << "th Fibonacci term is: " << nthTerm << endl;
    return 0;
}