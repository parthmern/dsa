#include <iostream>
using namespace std;

#include <string> 

void printPermutation(string &str, int i){

    if(i>= str.length()){
        cout << str << " ";
        return;
    }

    for(int j=i; j<str.length(); j++){
        swap(str[i], str[j]);   // swap
        printPermutation(str, i+1);     // rr
        swap(str[i], str[j]);   // BACKTRACKING
    }
}


int main(){

    string str = "abc";
    int i = 0;
    printPermutation(str,i);

    return 0;
}