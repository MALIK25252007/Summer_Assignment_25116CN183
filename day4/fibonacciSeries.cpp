#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter the number of terms in the Fibonacci series: ";
    cin >> n;

    unsigned long long a = 0, b = 1, nextTerm;
    cout << "Fibonacci Series: ";
    for (int i = 1; i <= n; ++i) {
        cout << a << " ";
        nextTerm = a + b;
        a = b;
        b = nextTerm;
    }
    cout << endl;
    return 0;
}