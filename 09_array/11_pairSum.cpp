// find 2 numbers which sum become = sum
// a[] = {1,3,5,7,2,4,6}
// sum = 9

// output
// make all pairs like
// (1, 3), (1, 5) (1, 7)(1, 2)(1, 4)(1, 6)
// (3, 5)(3, 7)(3, 2)(3, 4)(3, 6)
// (5, 7)(5, 2)(5, 4) (5, 6)
// (7, 2) (7, 4) (7, 6)
// (2, 4)(2, 6)
// (4, 6)

// now u can find sum for that element


#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int>arr{1, 3, 5, 7, 2, 4, 6};
    int sum = 9 ;

    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            cout << "(" << arr[i] << ", " << arr[j] << ")" ;
            if(arr[i]+ arr[j] == sum){
                cout << "MATCHED" << endl; 
            }
            cout<< endl;
        }
    }

    return 0;
}