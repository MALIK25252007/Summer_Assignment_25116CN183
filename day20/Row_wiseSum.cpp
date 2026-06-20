#include <iostream>
#include <vector>
using namespace std;
int main(){
    int rows, cols;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;
    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            cin >> matrix[i][j];
        }
    }

    cout << "Row-wise sum:" << endl;
    for (int i = 0; i < rows; ++i){
        int rowSum = 0;
        for (int j = 0; j < cols; ++j){
            rowSum += matrix[i][j];
        }
        cout << "Sum of row " << i + 1 << ": " << rowSum << endl;
    }
    return 0;
}