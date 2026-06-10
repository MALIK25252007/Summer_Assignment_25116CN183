#include <iostream>
using namespace std;

int main() {
    int rows;
    cout << "Enter number of rows: ";
    cin >> rows;
    for (int i = 1; i <= rows; ++i){
        char ch = 'A';
        for (int j = 1; j <= i; ++j) {
            cout << ch;
            ch++; 
        }
        cout << endl;
    }
    return 0;
}