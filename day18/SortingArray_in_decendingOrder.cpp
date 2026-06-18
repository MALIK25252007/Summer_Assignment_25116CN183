#include <iostream>
using namespace std;

int main(){
    int arr[] = {25, 11, 64, 12, 34, 90, 22};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "array before sorting :" ;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " " ;
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] < arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << endl <<"array after sorting in decending order :" ;
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}