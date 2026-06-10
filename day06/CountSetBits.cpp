#include <iostream>
using namespace std;
int countSetBits(unsigned int n){
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}
int main() {
    unsigned int num;
    cout << "Enter a non-negative integer: ";
    if (!(cin >> num)) { 
        cerr << "Invalid input!!! Please enter a valid non-negative integer.\n";
        return 1;
    }
    cout << "Number of set bits in " << num << " is: " << countSetBits(num)<< endl;
    return 0;
}