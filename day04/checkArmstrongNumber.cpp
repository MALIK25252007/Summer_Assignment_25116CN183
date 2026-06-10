#include <iostream>
#include <cmath>
using namespace std;
int main()  {
    int num, originalNum, remainder, result = 0;
    cout << "Enter an integer: ";
    cin >> num;
    int count = 0;
    originalNum = num;
    while (num > 0) {
        num /= 10;
        count++; 
    }
    num = originalNum; // reset num to original value for the next loop
    while (originalNum != 0) {
        remainder = originalNum % 10;
        result += pow(remainder, count);//power function from cmath library to calculate the power of the digit
        originalNum /= 10;
    } 
    if (result == num) {
        cout << num << " is an Armstrong number." << endl;
    } else {
        cout << num << " is not an Armstrong number." << endl;
    }

    return 0;
}
//we can also calculate the power of the digit manually without using the pow() function from cmath library. Below is the code for that:
/*#include <iostream>
using namespace std;

int main() {
    int originalNum, temp, remainder, digitCount = 0;
    int totalSum = 0;

    cout << "Enter an integer: ";
    cin >> originalNum;

    // Step 1: Count the number of digits
    temp = originalNum;
    while (temp != 0) {
        temp /= 10;
        digitCount++;
    }

    // Step 2 & 3: Separate digits, calculate power manually, and sum them up
    temp = originalNum;
    while (temp != 0) {
        remainder = temp % 10;

        // Manual Power Calculation (Replacing the pow() function)
        int powerResult = 1;
        for (int i = 0; i < digitCount; i++) {
            powerResult *= remainder;
        }

        totalSum += powerResult;
        temp /= 10;
    }

    // Step 4: Check if it's an Armstrong number
    if (totalSum == originalNum) {
        cout << originalNum << " is an Armstrong number." << endl;
    } else {
        cout << originalNum << " is not an Armstrong number." << endl;
    }

    return 0;
}*/