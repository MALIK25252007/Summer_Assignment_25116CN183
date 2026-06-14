#include <iostream>
using namespace std;

int findFrequency(int arr[], int size, int target){
    int count = 0;
    
    for (int i = 0; i < size; i++){
        if (arr[i] == target) {
            count++; 
        }
    }
    return count;
}

int main(){
    int arr[] = {10, 20, 30, 20, 40, 20, 50, 20, 60};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Array elements: ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Enter the element to find its frequency: ";
    cin >> target;

    int frequency = findFrequency(arr, size, target);
    cout << "The element " << target << " appears " << frequency << " time's in the array." << endl;

    return 0;
}