#include <iostream>
#include <string>
using namespace std;

int main(){
    int arr1[] = {1, 3, 5, 7};
    int n1 = 4;

    int arr2[] = {2, 4, 6, 8, 10};
    int n2 = 5;

    int totalSize = n1 + n2;
    int arr3[9]; 
    
    int i = 0; 
    int j = 0; 
    for (int k = 0; k < totalSize; k++){
        if (j >= n2 || (i < n1 && arr1[i] < arr2[j])){
            arr3[k] = arr1[i];
            i++;
        } else{
            arr3[k] = arr2[j];
            j++;
        }
    }

    for (int x = 0; x < totalSize; x++){
        cout << arr3[x] << " ";
    }
    cout << endl;
    return 0;
}