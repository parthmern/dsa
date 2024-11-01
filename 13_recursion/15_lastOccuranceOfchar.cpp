#include <iostream>
#include <string>

using namespace std;

void lastOccurance(string& s, char x, int& ans, int i){
    // basecase
    if( i>= s.length() ){
        return ;
    }

    if( s[i] == x ){
        ans = i;
    }

    lastOccurance(s,x,ans,i+1);

}

int main(){

    string s = "abcddedg";

    char x = 'd';
    
    int ans = -1;

    lastOccurance(s, x, ans, 0);

    cout << ans;


    return 0;
}