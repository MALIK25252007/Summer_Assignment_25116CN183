#include <iostream>
using namespace std;
int main(){
    int size;
    int evenCount = 0;
    int oddCount = 0;
    cout << "Enter the number of elements: ";
    cin >> size;
    int arr[size];
    cout << "Enter " << size << " numbers:\n";
    for (int i = 0; i < size; i++){
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
        if (arr[i] % 2 == 0){
            evenCount++;
        }else{
            oddCount++;
        }
    }

    cout << "\n-----------------------------\n";
    cout << "Total Even elements = " << evenCount << endl;
    cout << "Total Odd elements  = " << oddCount << endl;
    return 0;
}