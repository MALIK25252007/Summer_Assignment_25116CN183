#include <iostream>
#include <fstream>
using namespace std;

void saveArrayToFile(int arr[], int size){
    ofstream file("array_data.txt");
    if (file){
        file << size << "\n";
        for (int i = 0; i < size; i++){
            file << arr[i] << " ";
        }
        file.close();
    }
}

void loadArrayFromFile(int arr[], int &size){
    ifstream file("array_data.txt");
    if (file){
        file >> size;
        for (int i = 0; i < size; i++){
            file >> arr[i];
        }
        file.close();
    } else{
        size = 5;
        arr[0] = 10;
        arr[1] = 20;
        arr[2] = 30;
        arr[3] = 40;
        arr[4] = 50;
        saveArrayToFile(arr, size);
    }
}

void displayArray(int arr[], int size){
    cout << "\n=============================================\n";
    cout << "             CURRENT ARRAY STATE             \n";
    cout << "=============================================\n";
    cout << " Elements (" << size << " items): [ ";
    for (int i = 0; i < size; i++){
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << " ]\n";
    cout << "=============================================\n";
}

void insertElement(int arr[], int &size, int maxSize){
    if (size >= maxSize){
        cout << "\n[!] Error: Array Overflow! Cannot add more elements.\n";
        return;
    }

    int element, position;
    cout << "\nEnter element to insert: ";
    cin >> element;
    cout << "Enter index position (0 to " << size << "): ";
    cin >> position;

    if (position < 0 || position > size){
        cout << "\n!! Invalid index position!\n";
        return;
    }

    for (int i = size; i > position; i--){
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    size++;
    saveArrayToFile(arr, size);
    cout << "\n Element inserted successfully!\n";
}

void deleteElement(int arr[], int &size){
    if (size == 0){
        cout << "\n!! Error: Array Underflow! No elements to delete.\n";
        return;
    }

    int position;
    cout << "\nEnter index position to delete (0 to " << size - 1 << "): ";
    cin >> position;

    if (position < 0 || position >= size){
        cout << "\n!! Invalid index position!\n";
        return;
    }

    for (int i = position; i < size - 1; i++){
        arr[i] = arr[i + 1];
    }

    size--;
    saveArrayToFile(arr, size);
    cout << "\n Element removed successfully!\n";
}

void searchElement(int arr[], int size){
    if (size == 0){
        cout << "\n!! Array is empty.\n";
        return;
    }

    int target;
    cout << "\nEnter target element to find: ";
    cin >> target;

    bool found = false;
    for (int i = 0; i < size; i++){
        if (arr[i] == target){
            cout << "\n[== Element Found ==]";
            cout << "\n Target: " << target;
            cout << "\n Index Location: " << i << "\n";
            found = true;
            break;
        }
    }

    if (!found){
        cout << "\n Element " << target << " not found in the array.\n";
    }
}

int main(){
    int maxSize = 50;
    int arr[50];
    int size = 0;

    loadArrayFromFile(arr, size);

    int choice;
    do{
        cout << "\n=============================================";
        cout << "\n          ARRAY OPERATIONS CONSOLE           ";
        cout << "\n=============================================";
        cout << "\n 1. Display Array Elements";
        cout << "\n 2. Insert Element at Index";
        cout << "\n 3. Delete Element from Index";
        cout << "\n 4. Search Element (Linear Search)";
        cout << "\n 5. Exit System Framework";
        cout << "\n---------------------------------------------";
        cout << "\n Select Option Index (1-5): ";
        cin >> choice;

        switch (choice){
            case 1:
                displayArray(arr, size);
                break;
            case 2:
                insertElement(arr, size, maxSize);
                break;
            case 3:
                deleteElement(arr, size);
                break;
            case 4:
                searchElement(arr, size);
                break;
            case 5:
                cout << "\n Program terminated successfully. Goodbye!\n";
                break;
            default:
                cout << "\n!! Entry match unverified. Please choose a valid index.\n";
        }
    } while (choice != 5);

    return 0;
}