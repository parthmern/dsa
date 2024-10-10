#include <iostream>
using namespace std;

int findQuotient(int dividend, int divisor){

    int target = abs(dividend);
    
    
    int ans = -1;

    int start = 0;
    int end = abs(dividend) ;

    int mid = start + (end-start)/2 ;

    while (start <= end)
    {
        if(abs(divisor)*mid == target){
            // perfect sol
            ans = mid;
            break;
        }
        else if(abs(divisor)*mid < target){
            // right search
            start = mid + 1;
        }
        else{
            // left search
            end = mid - 1;

            // store ans
            ans = end;
        }
        
        mid = start + (end - start) / 2;

    }

    // mid = 4 + (3 - 4) / 2 = 4 + (-1) / 2 = 4 + 0 = 4;
    // why mid is 4 here?

    // if we do (Start/end)/2 = mid so we can get 3 as well
    
    cout << "end: " << end << " start: " << start << " mid: " << mid << " ans: " << ans << endl;
    
    ans = ((dividend>0 && divisor>0) || (dividend<0 && divisor<0) ) ? ans : ans*(-1) ; 
    return ans; // or end
   


}

int main(){

    int dividend = -22;
    int divisor = 1;

    cout << findQuotient(dividend, divisor);

    return 0;
}