#include <iostream>
using namespace std;
int main(){
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;
    if (size <= 0){
        cout << "Invalid array size!" << endl;
        return 1;
    }

    int arr[size];
    cout << "Enter " << size << " numbers:\n";
    for (int i = 0; i < size; i++){
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
    int largest = arr[0];
    int smallest = arr[0];

    for (int i = 1; i < size; i++){
        if (arr[i] > largest){
            largest = arr[i];
        }
        if (arr[i] < smallest){
            smallest = arr[i];
        }
    }

    cout << "\n--------------------------------------------------\n";
    cout << "Smallest element = " << smallest << endl;
    cout << "Largest element  = " << largest << endl;

    return 0;
}