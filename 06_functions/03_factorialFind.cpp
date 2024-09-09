// Input: 5
// Output: 120
// Explanation: 5! = 5 * 4 * 3 * 2 * 1 = 120

// Input: 4
// Output: 24
// Explanation: 4! = 4 * 3 * 2 * 1 = 24

// Base Case: N = 0 or N = 1, then factorial(N) = 1.

#include <iostream>
using namespace std;

long long int fact(long long int n){

    long long int fact = 1;  // To hold larger factorial values

    for(int i=1; i<=n; i++){
        fact = fact * i;
    }

    return fact ;

}

int main() {
    int num;
    
    cout << "Enter a positive integer: ";
    cin >> num;

    long long int ans = fact(num);

    cout << "Factorial of " << num << " = " << ans;

    return 0;  
}