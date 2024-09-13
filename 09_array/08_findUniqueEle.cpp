// Input Format:
//  arr[] = {2,2,1}
// Result:
//  1
// Explanation:
//  In this array, only the element 1 appear once and so it is the answer.

// Example 2:
// Input Format:
//  arr[] = {4,1,2,1,2}
// Result:
//  4
// Explanation:
//  In this array, only element 4 appear once and the other elements appear twice. So, 4 is the answer.


// ans
// use XOR
// 4^1^2^1^2 = 4
#include <iostream>
#include<vector>  
using namespace std;

int findUniqueElement(vector<int> arr){
    
    // arr[1] = 88;    // behaves differently from raw arrays -- vector done by PASS BY VALUE default
    
    int ans = 0 ; // inital with 0 because 0^anything = anything
    
    for(int i=0 ; i<arr.size() ; i++){
        //cout << "for "<< ans << "^" << arr[i] << "==>" ;
        
        ans = ans ^ arr[i];
        
        //cout << ans << endl ;
    }

    return ans;
}

int main(){

    vector<int> arr{4,1,2,1,2} ;

    int uniqueEle = findUniqueElement(arr) ;

    cout << uniqueEle << endl ;


    return 0;
}



// output
// for 0^4==>4
// for 4^1==>5
// for 5^2==>7
// for 7^1==>6
// for 6^2==>4
// 4


// explained = https://chatgpt.com/share/66e41b07-08e4-8010-adcb-8095fde1324a