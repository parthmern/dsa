#include <iostream>

using namespace std;

int sqrt(int n){

    int target = n ;

    int start = 0;
    int end = n;
    int mid = start + (end - start) / 2;

    int ans;

    while(start <= end){
        

        if(mid*mid == target){
            cout << "got" << mid << endl;
        }
        else if(mid*mid > target){ 
            
            //left
            end = mid - 1;

            // store
            ans = end;
        }
        else{
            // right
            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }

    cout << ans << end << endl;

    return end;


}

int main(){

    int num = 10;

    int ans = sqrt(num);
    double finalAns = ans;

    int precisonPoint = 3; 

    double step = 0.1;

    for(int i=0; i<precisonPoint; i++){

        for(double j=finalAns; j*j<=num ; j=j+step){
            finalAns = j;
        }

        step = step / 10;
    }

    cout << "final ans is=> "<< finalAns << endl;


    return 0;
}