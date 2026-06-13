#include <iostream>
using namespace std;
int main(){
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;
    int arr[size];
    cout << "Enter " << size << " integers:\n";
    for (int i = 0; i < size; i++){
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "\n-----------------------------\n";
    cout << "The elements in the array are:\n";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}