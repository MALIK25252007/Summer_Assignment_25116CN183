#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    int count = 0;
    while (n > 0) {
        n /= 10; // this will remove the last digit
        count++;  // it will increment the count of digits
    }
    cout << "The number of digits is: " << count << endl;
    return 0;
}