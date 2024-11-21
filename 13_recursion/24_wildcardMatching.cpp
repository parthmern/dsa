#include <iostream>
#include <string>

using namespace std;



bool isMatcherHelper(string &s, int si, string &p, int pi){

    // base case
    // 1) complete
    if( si==s.size() && pi==p.size()){
        return true;
    }

    // 2) s=abc p=abc****
    if(si==s.size()&&pi<p.size()){
        while(pi<p.size()){
            if(p[pi] != '*'){
                return false;
            }
            pi++;
        }
        return true;
    }


    // rr
    // single char matching
    if(s[si]==p[pi] || '?'==p[pi]){
        return isMatcherHelper(s,si+1,p,pi+1);
    }

    if(p[pi] =='*'){
        // treat '*' as empty or null
        bool caseA = isMatcherHelper(s,si,p,pi+1);

        // treat '*' consume 1 char
        bool caseB = isMatcherHelper(s,si+1,p,pi);

        return caseA || caseB;
    }


    return false ;

}

int main(){


    string s = "abcdefghi";
    string p = "abc?e*hi";

    cout << isMatcherHelper(s,0,p,0);




    return 0;
}