#include <iostream>
#include <vector>
using namespace std;

int main(){

    int N = 5;

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


    }

    
    // print ans
    for(int i=ans.size()-1; i>=0; i--){
        cout << ans[i] << " ";
    }

    return 0;
}