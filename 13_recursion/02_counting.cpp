#include <iostream>


using namespace std;

void counting(int n){
    
    // base condition
    if(n==0){
        return ;
    }

    // processing
    cout << "function is called for "<< n << endl;

    // recursive relation
    counting(n-1);

}

int main(){

    int n = 5;

    counting(n);

}