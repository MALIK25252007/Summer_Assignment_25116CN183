#include <iostream>
using namespace std;

int findMaximum(int num1, int num2){
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}

int main(){
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    int maxVal = findMaximum(a, b);

    cout << "The maximum value is: " << maxVal << endl;
    return 0;
}