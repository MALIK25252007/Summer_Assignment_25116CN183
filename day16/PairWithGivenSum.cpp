#include <iostream>

using namespace std;

bool findPair(int arr[], int size, int target){
    cout << endl <<"Pairs that make sum as " << target << " is :" << endl;
    for (int i = 0; i < size - 1; i++){
        for (int j = i + 1; j < size; j++){
            if (arr[i] + arr[j] == target){
                cout << arr[i] << " " << arr[j] << endl;
                return true;
            }
        }
    }
    return false;
}

int main(){
    int arr[] = {1, 4, 45, 6, 10, 8};
    int target = 16;
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    if (!findPair(arr, size, target)){
        cout << "No such pairs found!! " << endl;
    }

    return 0;
}