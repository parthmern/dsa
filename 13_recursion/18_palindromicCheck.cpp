#include <iostream>
#include <string>

using namespace std;

bool checkPalindromic(string& str, int s, int e){

    // base
    if( s>e ){
        return true;
    }

    if( str[s] != str[e] ){
        return false;
    }

    checkPalindromic(str, s+1, e-1);


}

int main(){

    string str = "racecar";

    cout << checkPalindromic( str, 0, str.length()-1 );


    return 0;
}