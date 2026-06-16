#include <iostream>
using namespace std;
int findMaxFrequencyElement(int arr[], int size){
    int maxElement = arr[0];
    int maxCount = 0;
    for (int i = 0; i < size; i++){
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j]){
                count++;
            }
        }
        if (count > maxCount){
            maxCount = count;
            maxElement = arr[i];
        }
    }
    return maxElement;
}

int main(){
    int arr[] = {1, 3, 2, 1, 4, 1, 3, 2, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl <<"Maximum frequency element is : " << findMaxFrequencyElement(arr, size) << endl;
    return 0;
}