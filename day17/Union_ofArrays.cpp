#include <iostream>
using namespace std;

int main(){
    int arr1[] = {1, 3, 4, 5, 7};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 3, 5, 6};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int maxSize = size1 + size2;
    int temp[maxSize];
    int unionSize = 0;
    cout << "1st array is :" ;
    for (int i = 0; i < size1; i++){
        cout << arr1[i] << " " ;
        temp[unionSize] = arr1[i];
        unionSize++;
    }
    cout << endl << "2nd array is : ";
    for (int i = 0; i < size2; i++){
        cout << arr2[i] << " " ;
        bool isDuplicate = false;
        for (int j = 0; j < size1; j++){
            if (arr2[i] == arr1[j]){
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate){
            temp[unionSize] = arr2[i];
            unionSize++;
        }
    }
    cout << endl << "array form by union of arr1 and arr2 : " ;
    for (int i = 0; i < unionSize; i++){
        cout << temp[i] << " ";
    }
    cout << endl;
    return 0;
}