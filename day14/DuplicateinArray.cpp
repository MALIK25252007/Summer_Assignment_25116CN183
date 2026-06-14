#include <iostream>
using namespace std;
void findDuplicates(int arr[], int size){
    bool hasDuplicates = false;

    cout << "Duplicate elements in the array: ";
    for (int i = 0; i < size; i++){
        bool isitFirstAppearance = true;
        
        for (int j = 0; j < i; j++){
            if (arr[i] == arr[j]){
               isitFirstAppearance = false;
               break;
            } 
        }     

        if (isitFirstAppearance){
            for (int j =i+1; j< size; j++){
                if (arr[i] == arr[j]){
                    cout << arr[i] << " ";
                    hasDuplicates = true;
                    break; 
                }
            }
        }
        }

    if (!hasDuplicates){
        cout << "None";
    }
    cout << endl;
}

int main(){
    int arr[] = {4, 3, 9, 2, 4, 1, 9, 4, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    findDuplicates(arr, size);

    return 0;
}