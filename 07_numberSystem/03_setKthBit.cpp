// https://www.geeksforgeeks.org/problems/set-kth-bit3724/1

#include <iostream>
using namespace std;

int main(){

    int N = 10 ;
    int K = 2; 

    int mask = 1 << K ;
    int ans = N | mask ;

    cout << ans << endl ;

    return 0;
}