#include <iostream>
#include <vector>
using namespace std;
int main(){
    int r1, c1, r2, c2;
    cout << "Enter rows and columns for first matrix: ";
    cin >> r1 >> c1;

    cout << "Enter rows and columns for second matrix: ";
    cin >> r2 >> c2;

    if (c1 != r2){
        cout << "Matrix multiplication not possible." << endl;
        return 0;
    }
    vector<vector<int>> a(r1, vector<int>(c1));
    vector<vector<int>> b(r2, vector<int>(c2));
    vector<vector<int>> product(r1, vector<int>(c2, 0));

    cout << "Enter elements of matrix 1:" << endl;
    for (int i = 0; i < r1; ++i){
        for (int j = 0; j < c1; ++j){
            cin >> a[i][j];
        }
    }

    cout << "Enter elements of matrix 2:" << endl;
    for (int i = 0; i < r2; ++i){
        for (int j = 0; j < c2; ++j){
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < r1; ++i){
        for (int j = 0; j < c2; ++j){
            for (int k = 0; k < c1; ++k){
                product[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    cout << "Resultant Matrix:" << endl;
    for (int i = 0; i < r1; ++i){
        for (int j = 0; j < c2; ++j){
            cout << product[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}