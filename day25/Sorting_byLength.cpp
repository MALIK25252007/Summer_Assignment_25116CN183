#include <iostream>
#include <string>
using namespace std;

int main() {
    string words[] = {"elephant", "cat", "banana", "dog", "hi"};
    int n = 5;
    cout << "words before sorting : ";
    for (int i = 0; i < n - 1; i++){
        cout << words[i] << " ";
    }
    cout << endl << "Words after sorting according to their length : " ;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (words[j].length() > words[j + 1].length()) {
                string temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << words[i] << " ";
    }
    cout << endl;

    return 0;
}