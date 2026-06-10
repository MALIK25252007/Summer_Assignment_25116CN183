#include <iostream>
using namespace std;
int Power(int base, int exp){
    int ans = 1;
    for(int i=0; i< exp; i++){
        ans *= base;
    }
    return ans;
}
int main(){
    int base, exp;
    cout << "Enter base and exponent: ";
    cin >> base >> exp;
    cout << base << " raised to the power " << exp << " is : " << Power(base, exp) << endl;
    return 0;
}