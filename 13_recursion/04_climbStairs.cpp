#include <iostream>

using namespace std;

int climbStairs(int n){

    // base case
    if(n==0) return 1;
    if(n==1) return 1;

    int ans = climbStairs(n-1)+climbStairs(n-2);

    return ans;
 
}

int main(){

    cout << climbStairs(5);

    return 0;
}