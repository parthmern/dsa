#include <iostream>
#include <algorithm>

using namespace std;

string addString(string &s1, string &s2, int p1, int p2, int carry, string &ans){

    // base 
    if( p1 < 0 && p2 < 0 ){
        if(carry!=0){
            ans.push_back(carry+'0');
            return string(1,carry+ '0');
        }
        return "";
    }

    int n1 = ( p1>=0 ? s1[p1] - '0' : '0');
    //int n2 = s2[p2] - '0';  // int convert
    int n2= ( p2>=0 ? s2[p2] - '0' : '0');

    int total = n1+n2+carry;

    int digit = total%10;
    carry = total/10;

    string rAns = "";

    ans.push_back(digit+'0');
    rAns.push_back(digit+'0');

    // rr
    rAns += addString(s1,s2,p1-1, p2-1, carry, ans);
    return rAns;
}

int main(){


    string s1 = "1234";
    string s2 = "5678";

    int p1 = s1.length()-1;
    int p2 = s2.length()-1;

    int carry = 0;

    string ans ="";

    cout << addString(s1, s2, p1, p2, carry, ans) << endl; 

    reverse(ans.begin(), ans.end());

    cout << ans;

    return 0;
}