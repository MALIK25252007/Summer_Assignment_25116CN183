#include <iostream>
using namespace std;
int main(){
    long n;
    cout << "Enter a number: ";
    cin >> n;
    long largestPrimeFactor =-1;
    while (n % 2 == 0) {
        largestPrimeFactor = 2;
        n /= 2;
    }
    for (long i = 3; i*i <= n; i += 2){
        while (n % i == 0) {
            largestPrimeFactor = i;
            n /= i;
        }
    }
    if (n > 2){
        largestPrimeFactor = n;
    }
    if (largestPrimeFactor == -1){
        cout << "no prime factors found." << endl;
        return 0;
    }
    cout << "The largest prime factor is: " << largestPrimeFactor << endl;
    return 0;
}