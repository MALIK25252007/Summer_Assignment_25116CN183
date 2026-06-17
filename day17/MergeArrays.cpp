#include <iostream>
using namespace std;

int main(){
    int arr1[] = {1, 3, 5, 7};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {2, 4, 6, 8};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = size1 + size2;
    int arr3[size3];
    cout << "1st array is :" ;
    for (int i = 0; i < size1; i++){
        cout << arr1[i] << " " ;
        arr3[i] = arr1[i];
    }
    cout << endl << "2nd array is : ";
    for (int i = 0; i < size2; i++){
        cout << arr2[i] << " " ;
        arr3[size1 + i] = arr2[i];
    } 
    cout << endl << "array form by merging arr1 and arr2 : " ;
    for (int i = 0; i < size3; i++){
        cout << arr3[i] << " ";
    }
    cout << endl;
    return 0;
}