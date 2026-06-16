#include <iostream>
using namespace std;
int removeDuplicates(int arr[], int size){
    if (size == 0) return 0;
    int newSize = 1; 
    for (int i = 1; i < size; i++){
        bool isDuplicate = false;
        for (int j = 0; j < newSize; j++){
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate){
            arr[newSize] = arr[i];
            newSize++;
        }
    }
    return newSize;
}
int main(){
    int arr[] = {2, 3, 2, 4, 5, 3, 6, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Array before deleting the duplicate elements: ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    int n = removeDuplicates(arr, size);
    cout << endl << "Array after deleting the duplicate elements: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}