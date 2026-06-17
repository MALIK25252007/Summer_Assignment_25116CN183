#include <iostream>
using namespace std;
int main(){
    int height;
    cout << "Enter height of pyramid: ";
    cin >> height;
    for(int i = 1; i <= height; i++){ 
        for(int s = 1; s <= height - i; s++){ 
            cout << " "; 
        } 
        for(int j = 1; j <= (2 * i - 1); j++){ 
            cout << "*"; 
        } 
        cout << endl; 
    } 
    return 0;
}