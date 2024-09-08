

#include <iostream>
using namespace std;

int main()
{

    for (int i = 0; i < 5; i++)
    {
        if (i == 2)
        {
            continue;
        }
        cout << i << " ";
    }
    // Output: 0 1 3 4

    for (int i = 0; i < 5; i++)
    {
        if (i == 3)
        {
            break;
        }
        cout << i << " ";
    }
    // Output: 0 1 2
}