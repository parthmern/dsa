#include <iostream>
#include <string.h>
using namespace std;


int myStrLen(char charArray[]) {
    int length = 0;
    int i = 0;

    while (charArray[i] != '\0') {
        length++;
        i++;
    }

    return length;
}

int reverseCharArray(char arr[]){

    int n = myStrLen(arr);

    int i = 0 ;
    int j = n - 1;

    while(i<=j){
        swap(arr[i], arr[j]);
        i++;
        j--;
    }

    cout << "reverse arr => " << arr << endl;
}

int main(){


    char name[100];

    // cin >> name;

    // cout << name << endl;

    // cout << "new input method" << endl;
    // char ch[100];

    // ch[0] = 'a';
    // ch[1] = 'b';
    // cin >> ch[2];

    // cout << ch << endl;

    cout << "with space " << endl;

    char ch[100];

    // cin >> ch ;

    // cout << ch << endl;

    // cin.getline(input, MAX_LENGTH);

    cin.getline(ch, 50);

    cout << ch << endl;

    cout << strlen(ch) << endl;
    cout << myStrLen(ch) << endl;

    reverseCharArray(ch); // pass by ref
    


}