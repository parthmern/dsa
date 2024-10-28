#include <iostream>


using namespace std;

int factorial(int n){
    cout << "function is called for "<< n << endl;

    if(n==1){
        return 1;
    }

    int ans = n * factorial(n-1);

    return ans;
}

int main(){

    int n = 5;

    cout << factorial(n);

}