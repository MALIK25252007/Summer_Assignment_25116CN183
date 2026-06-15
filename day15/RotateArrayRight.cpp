#include <iostream>
using namespace std;
void rightRotateTemp(int arr[], int d, int n){
    d = d % n; 
    int temp[d];

    for (int i = 0; i < d; i++){
        temp[i] = arr[n - d + i];
    }

    for (int i = n - 1; i >= d; i--){
        arr[i] = arr[i - d];
    }

    for (int i = 0; i < d; i++){
        arr[i] = temp[i];
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 2;

    cout << "Original array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    rightRotateTemp(arr, d, n);
    cout << "Array after right rotation: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}