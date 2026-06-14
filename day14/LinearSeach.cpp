#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target){
    for (int i = 0; i < size; i++){
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {2, 8, 4, 6, 5, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Array elements: ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Enter the number you want to search : ";
    cin >> target;
    int result = linearSearch(arr, size, target);

    if (result != -1){
        cout << "Element found at index: " << result << endl;
    }else{
        cout << "Element not found in the array!!!!!!" << endl;
    }

    return 0;
}