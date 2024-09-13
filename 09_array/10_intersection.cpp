// Input:

// Arr1 = [1, 2, 3, 4, 5, 6]
// Arr2 = [1, 2, 3, 4, 5]

// Output:

// [1, 2, 3, 4, 5]

// Explanation: Common elements between Arr1 and Arr2 is 1, 2, 3, 4, 5. So, [1, 2, 3, 4, 5] is the output.

// Input:

// Arr1 = [1, 2, 4]
// Arr2 = [5, 6, 7]

// Output:

// []

#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> arra{1, 2, 3, 3, 4, 6, 8};
    vector<int> arrb{3, 3, 4, 10};

    vector<int> ans;

    for (int i = 0; i < arra.size(); i++)
    {
        for (int j = 0; j < arrb.size(); j++)
        {
            if(arra[i] == arrb[j]){

                // mark - getting output like 3 3 3 3 4 so solve this
                arrb[j] = -1 ;  // u can use INT_MIN if there are also neg values

                ans.push_back(arra[i]) ;

                // break ;    // can work same
                
            }
        }
    }

    // print ans
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}