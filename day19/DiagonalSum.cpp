#include <iostream>
#include <vector>
using namespace std;

int main(){
    int size;

    cout << "Enter the size of the square matrix: ";
    cin >> size;

    vector<vector<int>> matrix(size, vector<int>(size));
    int primarySum = 0;
    int secondarySum = 0;

    cout << "\nEnter elements for the matrix:\n";
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < size; i++){
        primarySum += matrix[i][i];
        secondarySum += matrix[i][size - 1 - i];
    }

    cout << "\nMatrix: \n";
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }

    cout << "\nSum of Primary Diagonal: " << primarySum << endl;
    cout << "Sum of Secondary Diagonal: " << secondarySum << endl;

    return 0;
}