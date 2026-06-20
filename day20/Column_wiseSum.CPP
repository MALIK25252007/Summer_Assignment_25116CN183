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
    cout << "Column-wise sum:" << endl;
    for (int j = 0; j < cols; ++j){
        int colSum = 0;
        for (int i = 0; i < rows; ++i){
            colSum += matrix[i][j];
        }
        cout << "Sum of column " << j + 1 << ": " << colSum << endl;
    }
    return 0;
}