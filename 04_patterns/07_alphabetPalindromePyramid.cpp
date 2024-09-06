// A
// ABA
// ABCBA
// ABCDCBA
// ABCDEDCBA

// think like all star pyramid first

#include <iostream>
using namespace std;

// 1
// 121
// 12321
// 1234321
// 123454321

// first print like this
// then replace 1->A ,2->B, 3->C, 4->D

// how to replace
// int m = 1;
// char ch = m + 'A';     // gives 'B';

int main()
{
    int n = 5;
    for (int i = 0; i < n; i++)
    {

       // beg counting
       int j;
        for (j = 0; j < i+1; j++)
        {
            //cout<<j+1;

            int ans = j+1;
            char ch = ans + 'A' - 1 ;
            cout << ch; 
        }

        // reverse counting
        j = j-1;

        for(; j>=1; j--){
            // cout << j;

            int ans = j;
            char ch = ans + 'A' - 1 ;
            cout << ch; 
        }

        cout << endl;
    }
    return 0;
}