#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int sum = 0;
    while (n > 0) {
        sum += n % 10; // to add last digit into the sum
        n /= 10; //to remove the last digit whichis already added to sum
    }
    cout << sum << endl;
    return 0;
}