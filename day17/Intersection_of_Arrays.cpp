#include <iostream>
using namespace std;

int main(){
    int arr1[] = {1, 3, 4, 5, 7};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "1st array is :" ;
    for (int i = 0; i < size1; i++)
        cout << arr1[i] << " " ;
    int arr2[] = {2, 3, 5, 6};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << endl << "2nd array is : ";
    for (int i = 0; i < size2; i++)
        cout << arr2[i] << " " ;
    cout << endl << "array form by intersection of arr1 and arr2 : " ;
    for (int i = 0; i < size1; i++){
        for (int j = 0; j < size2; j++){
            if (arr1[i] == arr2[j]){
                cout << arr1[i] << " ";
                break;
            }
        }
    }
    cout << endl;
    return 0;
}