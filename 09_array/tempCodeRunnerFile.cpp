#include <iostream>
#include <vector>
using namespace std;

int main(){

    int N = 4;

    vector<int> ans;

    ans.push_back(1);

    int carry = 0;
    for(int i=2; i<=N; i++){

        for(int j=0; j<ans.size(); j++ ){
            int x = ans[j] * i + carry;
            ans[j] = x % 10;
            carry = x / 10;
        }

        while (carry) {
            ans.push_back(carry % 10);
            carry /= 10;
        }

        carry = 0;

        // print ans
        for(int i=0; i< ans.size(); i++){
            cout << ans[i] << endl;
        }

    }

    return 0;
}