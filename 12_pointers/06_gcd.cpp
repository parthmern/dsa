#include <iostream>

using namespace std;

int gcd(int a, int b)
{

    while (a != b)
    {
        if (a == 0)
            return b;

        if (b == 0)
            return a;

        if (a > b)
        {
            a = a - b;
        }
        else if (b > a)
        {
            b = b - a;
        }
        
    }
    return a;
}

int main()
{

    cout << gcd(72,24);

    return 0;
}