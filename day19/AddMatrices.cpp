#include <iostream>
#include <vector>
using namespace std;
int main(){
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    vector<vector<int>> matrix1(rows, vector<int>(cols));
    vector<vector<int>> matrix2(rows, vector<int>(cols));
    vector<vector<int>> sum(rows, vector<int>(cols));

    cout << "\nEnter elements for the first matrix:\n";
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix1[i][j];
        }
    }

    cout << "\nEnter elements for the second matrix:\n";
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix2[i][j];
        }
    }

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    cout << "\nResultant Matrix (Sum):\n";
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cout << sum[i][j] << "\t";
        }
        cout << "\n";
    }
    return 0;
}