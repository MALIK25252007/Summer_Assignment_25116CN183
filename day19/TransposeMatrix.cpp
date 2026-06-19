#include <iostream>
#include <vector>
using namespace std;
int main(){
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    vector<vector<int>> transpose(cols, vector<int>(rows));

    cout << "\nEnter elements for the matrix:\n";
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            transpose[j][i] = matrix[i][j];
        }
    }

    cout << "\nOriginal Matrix:\n";
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }

    cout << "\nTransposed Matrix:\n";
    for (int i = 0; i < cols; i++){
        for (int j = 0; j < rows; j++){
            cout << transpose[i][j] << "\t";
        }
        cout << "\n";
    }
    return 0;
}