// 12548, the reverse of the number num is 84521

//  rev_num = rev_num*10 + num%10;

// ===================
// N = 123
// let ans = 0, 

// N= 123
// rem = N % 10 = 123 % 10 = 3
// ans = ans * 10 + rem == 0*10+3 = 3

// N = 123/10 = 12
// rem = N % 10 = 12 % 10 = 2
// ans = ans * 10 + rem == 3*10+2 = 32

// N = 12/10 = 1
// rem = N % 10 = 1 % 10 = 1
// ans = ans * 10 + rem == 32*10+1 = 321
#include <iostream>

int reverse(int n) {
    int ans = 0;
    int rem = 0;

    while(n > 0) {
        int digit = n % 10;
        ans = ans * 10 + digit;
        n = n / 10; 
    }

    return ans;
}

using namespace std;

int main() {
    int a = reverse(123);
    cout << a;

    return 0;
}



// int reverseDigits(int num) 
// { 
//     int rev_num = 0; 
//     while (num > 0) { 
//         rev_num = rev_num * 10 + num % 10; 
//         num = num / 10; 
//     } 
//     return rev_num; 
// } 