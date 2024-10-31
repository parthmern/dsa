#include <iostream>
#include <limits.h>

using namespace std;

int cutIntoSegment(int n, int x, int y, int z){

    // base case
    if( n == 0 ){
        return 0;
    }

    if( n<0 ){
        return INT_MIN;
    }

    int a = cutIntoSegment(n-x, x,y,z) + 1;

    int b = cutIntoSegment(n-y, x,y,z) + 1;

    int c = cutIntoSegment(n-z, x,y,z) + 1;

    int ans = max( a, max(b,c) );
    
    return ans;



}

int main(){

    int n = 7;
    int x = 5;
    int y = 2;
    int z = 2;

    int ans = cutIntoSegment(n, x,y,z);

    if(ans<0){
        cout << "ans is" << 0 << endl;
    }
    
    cout << "ans is" << ans << endl;
    

    return 0;
}