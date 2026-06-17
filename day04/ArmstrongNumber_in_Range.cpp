#include <iostream>
#include <cmath>
using namespace std;
int countDigits(int num){
    int count = 0;
    while (num > 0) {
        count++;
        num /= 10;
    }
    return count;
}
bool isArmstrong(int num){
    int original = num;
    int digits = countDigits(num);
    int sum = 0;
    
    while (num > 0){
        int digit = num % 10;
        sum += pow(digit, digits);
        num /= 10;
    }
    
    return sum == original;
}

int main(){
    int lower, upper;
    cout << "Enter lower limit: ";
    cin >> lower;
    cout << "Enter upper limit: ";
    cin >> upper;
    bool found = false;
    bool first = 0;
    for (int i = lower; i <= upper; i++){
        if (isArmstrong(i)){
            first = 1;
            if (first==1){
              cout << "\nArmstrong numbers between " << lower << " and " << upper << " are:\n";

            }
            if (found){
                cout << ", ";
            }
            cout << i << " ";
            found = true;
            first+= 1;
        }
    }
    if (!found){
        cout << "there is no armstrong number lies in this range";
    }   
    cout << endl;
    return 0;
}