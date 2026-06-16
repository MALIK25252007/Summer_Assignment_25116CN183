#include <iostream>
using namespace std;

int findMissingNumber(int arr[], int size){
    int n = size + 1;
    int totalSum = n * (n + 1) / 2;
    int currentSum = 0;
    
    for (int i = 0; i < size; i++){
        currentSum += arr[i];
    }
    
    return totalSum - currentSum;
}

int main(){
    int arr[] = {1, 2, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Missing number in array is :" << findMissingNumber(arr, size) << endl;
    return 0;
}