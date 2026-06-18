#include <iostream>
using namespace std;

int main(){
    int arr[] = {11, 12, 22, 25, 34, 64, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 25;
    cout << "Given array :" ;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " " ;
    cout << endl << "Element to be found in array is :" << target << endl ;
    int low = 0;
    int high = n - 1;
    int result = -1;

    while (low <= high){
        int mid = low + (high - low) / 2;

        if (arr[mid] == target){
            result = mid;
            break;
        }
        if (arr[mid] < target){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (result != -1){
        cout << "Element found at index: " << result << endl;
    }else{
        cout << "Element not found" << endl;
    }

    return 0;
}