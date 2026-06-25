#include <iostream>
#include <string>
using namespace std;

int main() {
    string arr[] = {"tarun", "malik", "arrived"};
    int n = 3;
    cout << "Given strings are : " ;
    for (int i = 0; i < n; i++){
        cout << arr[i] << " " ;
    }
    string first = arr[0];
    string common = "";
    cout << endl;
    for (int i = 0; i < first.length(); i++){
        char ch = first[i];
        bool isCommon = true;

        for (int j = 1; j < n; j++){
            bool foundInCurrent = false;
            for (int k = 0; k < arr[j].length(); k++){
                if (arr[j][k] == ch){
                    arr[j][k] = '*'; 
                    foundInCurrent = true;
                    break;
                    
                }
            }
            if (!foundInCurrent){
                isCommon = false;
                break;
            }
        }

        if (isCommon){
            common += ch;
        }
    }

    if (common.length() > 0){
        for (int i = 0; i < common.length(); i++){
            cout << "common characters in these strings are :" << common[i] << " ";
        }
    }else{
        cout << "No common characters found.";
    }
    cout << endl;

    return 0;
}