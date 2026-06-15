#include <iostream>
using namespace std;
void moveZeroesToEnd(int arr[], int n){
    int count = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] != 0){
            int temp = arr[i];
            arr[i] = arr[count];
            arr[count] = temp;
            
            count++;
        }
    }
}

int main(){
    int arr[] = {4, 0, 0, 1, 0, 8, 9, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    moveZeroesToEnd(arr, n);
    cout << "Array after moving zeroes to end: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}