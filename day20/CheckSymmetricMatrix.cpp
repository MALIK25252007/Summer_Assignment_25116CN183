#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cout << "Enter the size of the square matrix: ";
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> matrix[i][j];
        }
    }
    bool isSymmetric = true;

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < i; ++j){
            if (matrix[i][j] != matrix[j][i]){
                isSymmetric = false;
                break;
            }
        }
        if (!isSymmetric){
            break;
        }
    }
    if (isSymmetric){
        cout << "The matrix is symmetric." << endl;
    } else {
        cout << "The matrix is not symmetric." << endl;
    }

    return 0;
}