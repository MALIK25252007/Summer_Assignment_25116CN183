#include <iostream>
using namespace std;

int main(){
    int arr1[] = {10, 15, 20, 25, 30};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {15, 5, 30, 20, 45};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

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