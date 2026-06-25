#include <iostream>
#include <string>
using namespace std;

int main(){
    string names[] = {"Tarun", "Arun", "Virat", "Elon", "Thala", "Vijay"};
    int n = 6;
    cout << "Names before sorting : ";
    for (int i = 0; i < n - 1; i++){
        cout << names[i] << " ";
    }
    cout << endl << "Names after sorting alphabatically : " ;
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (names[j] > names[j + 1]) {
                string temp = names[j];
                names[j] = names[j + 1];
                names[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++){
        cout << names[i] << " ";
    }
    cout << endl;
    return 0;
}