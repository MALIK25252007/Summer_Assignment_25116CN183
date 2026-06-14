#include <iostream>
using namespace std;

int findSecondLargest(int arr[], int size){
    int largest = arr[0];
    int secondLargest = arr[0];

    for (int i = 0; i < size; i++){

        if (arr[i] > largest){
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest){
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

int main(){
    int arr[] = {32, 35, 38, 101, 10, 4, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Array elements: ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    int result = findSecondLargest(arr, size);
    cout << "The second largest element is: " << result << endl;
   

    return 0;
}