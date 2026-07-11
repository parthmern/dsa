#include <iostream>
#include <vector>
using namespace std;

// Prints all subarrays in arr[0..n-1]
void subArray(vector<int> &arr)
{
    int n = arr.size();

    // Pick starting point
    for (int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            // [ i ... j ]
            for (int k = i; k <= j; k++)
                cout << arr[k];
            cout << endl;
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    cout << "All Non-empty Subarrays\n";
    subArray(arr);
    return 0;
}

// 1
// 12
// 123
// 1234
// 2
// 23
// 234
// 3   
// 34
// 4