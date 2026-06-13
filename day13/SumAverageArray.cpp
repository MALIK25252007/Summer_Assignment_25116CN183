#include <iostream>
using namespace std;
int main(){
    int size;
    int sum = 0;
    int average;
    cout << "Enter the number of elements: ";
    cin >> size;
    int arr[size];
    cout << "Enter " << size << " numbers:\n";
    for (int i = 0; i < size; i++){
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
        sum += arr[i]; 
    }
    average = (sum) / size;

    cout << "\n-----------------------------\n";
    cout << "Sum of elements     = " << sum << endl;
    cout << "Average of elements = " << average << endl;
    return 0;
}