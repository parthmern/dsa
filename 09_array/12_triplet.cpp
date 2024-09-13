
// (1, 3, 5)
// (1, 3, 7)
// (1, 3, 2)
// (1, 3, 4)
// (1, 3, 6)
// ...

#include <iostream>
#include <vector>
using namespace std; 

int main() {
    vector<int> a = {1, 3, 5, 7, 2, 4, 6};  
    int sum = 9 ;

    for (int i = 0; i < a.size(); i++) {
        for (int j = i + 1; j < a.size(); j++) {
            for (int k = j + 1; k < a.size(); k++) {
                cout << "(" << a[i] << ", " << a[j] << ", " << a[k] << ")" ;

                if(a[i]+a[j]+a[k] == sum){
                    cout << "MATCHED";
                }

                cout << endl;

            }
        }
    }

    return 0;
}
