#include <iostream>
#include <cmath>
using namespace std;

// Function to count the number of digits in a number
int countDigits(int num) {
    int count = 0;
    while (num > 0) {
        count++;
        num /= 10;
    }
    return count;
}

// Function to check if a number is Armstrong number
bool isArmstrong(int num) {
    int original = num;
    int digits = countDigits(num);
    int sum = 0;
    
    while (num > 0) {
        int digit = num % 10;
        sum += pow(digit, digits);
        num /= 10;
    }
    
    return sum == original;
}

int main() {
    int lower, upper;
    
    // Get input from user
    cout << "Enter lower limit: ";
    cin >> lower;
    cout << "Enter upper limit: ";
    cin >> upper;
    
    // Find and display Armstrong numbers in the range
    bool found = false;
    bool first = 0;// to check if the header is printed or not
    
    for (int i = lower; i <= upper; i++) {
        if (isArmstrong(i)) {
            first = 1;
            if (first==1){
              cout << "\nArmstrong numbers between " << lower << " and " << upper << " are:\n";

            }


            if (found) {
                cout << ", ";
            }

            cout << i << " ";
            found = true;
            first+= 1;// to avoid printing the header multiple times
        }
    }
    
    // If no Armstrong number found
    if (!found) {
        cout << "there is no armstrong number lies in this range";
    }
    
    cout << endl;
    return 0;
}


    