// decimal to binary formula

// let ans = 0 , i = 0
// ans = (digit*10^i) + ans
// where digit = reminder 

// find for 10
// (10/2=5) and (10%2 = 0) so -> 0 * 10^0 + 0 = 0   and i++
// (5/2=2) and  (5%2=1)    so -> 1 * 10^1 + 0 = 10      and i++
// (2/2=1) and  (2%2=0)    so -> 0 * 10^2 + 10 = 10      and i++
// (1/2=0) and  (1%2=1)    so -> 1 * 10^3 + 10 = 1010      and i++


#include <iostream>
#include <cmath>

using namespace std; 

// int decialToBinaryMethod1(int n){

//     while (n>0)
//     {
//         int bit = n % 2 ;
//         cout << bit << endl;
//         n = n / 2 ;
//     }

//     cout << "not in reverse order -- not actual method" << endl ;
    
//     return 0;
// }

int decimalToBinaryMethod1(int n){
    // division method 
    int binaryno = 0;
    int i = 0;

    while (n>0)
    {
        int bit = n % 2;
        binaryno = bit * pow(10, i++) + binaryno ;
        n = n / 2;
    }
    
    return binaryno ;
}

int decimalToBinaryMethod2(int n){
    // bitwise method 
    int binaryno = 0;
    int i = 0;

    while (n>0)
    {
        int bit = (n&1);        // and by 1
        binaryno = bit * pow(10, i++) + binaryno ;
        n = n >> 1;             // 1 right shift
    }
    
    return binaryno ;
}

int binaryToDecimal(int n){

    // - multiply each digit with its place value and then sum
    // 1010
    // 1*2^3 + 0*2^2 + 1*2^1 + 0*2^0 = 10 

    int decimal = 0 ;
    int i = 0 ;

    while(n){
        int bit = n % 10;
        decimal = decimal + bit * pow(2, i++);
        n = n/10 ;
    }

    return decimal;
}

int main(){
    
    cout << decimalToBinaryMethod1(2);

    cout << endl; 

    cout<< decimalToBinaryMethod2(2);

    cout << endl; 

    cout << binaryToDecimal(1010);

    return 0;
}