#include <iostream>
using namespace std;
void leftRotateTemp(int arr[], int d, int n){
    d = d % n;
    int temp[d];
    for (int i = 0; i < d; i++){
        temp[i] = arr[i];
    }

    for (int i = d; i < n; i++){
        arr[i - d] = arr[i];
    }

    for (int i = 0; i < d; i++){
        arr[n - d + i] = temp[i];
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 2;

    cout << "Original array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    leftRotateTemp(arr, d, n);

    cout << "Array after left rotation: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}