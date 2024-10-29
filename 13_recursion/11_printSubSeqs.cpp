#include <iostream>
#include <string>
using namespace std;

void printSubstring(string str, string output, int i){

    //base case
    if(i>= str.length()){
        cout << output << endl;
        return;
    }

    // rr
    // 1)exclude
    printSubstring(str, output, i+1);

    // 2)include
    output.push_back(str[i]);
    printSubstring(str, output, i+1);

}


int main(){

    string str = "abc";
    string output = "";

    int i = 0;
    printSubstring(str, output, i);

    return 0;
}