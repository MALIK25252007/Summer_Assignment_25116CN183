#include <iostream>
using namespace std;
int main (){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int product = 1;
    while (n > 0){
        product *= n % 10;
        n /= 10; 
    }
    cout << product << endl;
    return 0;
}