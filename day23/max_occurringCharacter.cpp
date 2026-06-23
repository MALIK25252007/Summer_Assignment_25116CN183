#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    int frequency[256] = {0};

    cout << "Enter a string: ";
    getline(cin, str);

    for (int i = 0; i < str.length(); i++){
        frequency[(unsigned char)str[i]]++;
    }

    int max = 0;
    char character ;
    for (int i = 0; i < 256; i++){
        if (frequency[i] > max){
           max = frequency[i]; 
           character =(char)i;
        }
    }

    if (max != 0 ){
        cout << "Maximum occuring characters with occurence of " << max << " times is :" << endl;
    
        for (int i = 0; i < 256; i++){
            if (frequency[i] == max){
                cout << (char)i << " ";
            }
        }   
    }else{
        cout << "you input a empty string";
    }
    return 0;
}