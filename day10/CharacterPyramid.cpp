#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter number of rows: ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int s = 1; s <= n - i; s++) cout << " ";
            char ch = 'A';
        for (int j = 1; j <= i; j++) cout << ch++;
            ch -= 2;
        for (int j = 1; j < i; j++)
            cout << ch--;

        cout << endl;
    }
    
    return 0;
}