#include <iostream>

using namespace std;

// 0        1       1      2        3      4
// first  second  thrid  fourth  fifth  sixth

int fibo(int n){

    // base case
    if(n==1) return 0;  // first term
    if(n==2) return 1;  // second term

    // recursive rel [ f(n) = f(n-1)+f(n-2) ]
    int ans = fibo(n-1) + fibo(n-2) ;

    return ans;
}

int main(){

    int n = 5;

    int ans = fibo(n);

    cout << "n th term is =>" << ans;

}