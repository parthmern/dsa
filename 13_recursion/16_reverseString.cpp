#include <iostream>

using namespace std;

void reverse(string &s, int start, int end){

    //base
    if( start>=end ){
        return;
    }

    swap(s[start], s[end]);

    reverse(s, start+1, end-1);

}

int main(){

    string str = "parth";
    int s = 0, e = str.length()-1;
    reverse(str,s,e);

    cout << str;

    return 0;
}