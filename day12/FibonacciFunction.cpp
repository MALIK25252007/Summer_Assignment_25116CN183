#include <iostream>
using namespace std;
void printFibonacci(int n){
    int first = 0;
    int second = 1;
    int next;
    cout << "Fibonacci Sequence: ";

    for (int i = 1; i <= n; i++){
        if (i == 1){
            cout << first << " ";
            continue;
        }
        if (i == 2){
            cout << second << " ";
            continue;
        }
        next = first + second;
        first = second;
        second = next;  
        cout << next << " ";
    }
    cout << endl;
}
int main(){
    int terms;
    cout << "Enter the number of terms: ";
    cin >> terms;
    if (terms <= 0){
        cout << "Please enter a number greater than 0." << endl;
    }else{
        printFibonacci(terms);
    }

    return 0;
}