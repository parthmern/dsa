#include <iostream>
#include <vector>
using namespace std;

int bsInNearlySorted(vector<int>arr, int target){

    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end-start)/2 ;

    while (start <= end)
    {
        if(arr[mid] == target){
            return mid;
        }
        // mid+1< end to optimize more
        else if(mid+1< arr.size() && arr[mid+1] == target){
            return (mid+1);
        }
        // mid-1>= start to optimize more
        else if(mid-1>=0 && arr[mid-1] == target){
            return (mid-1);
        }

        else if( arr[mid] < target){
            // right search
            start = mid + 2;
        }
        else{
            // left s
            end = mid - 2;
        }

        mid = start + (end-start)/2 ;
    }

    return -1;
    

}


int main(){

    vector <int>v {10,3,40,20,50,80,70};
    int target = 70;

   cout <<  bsInNearlySorted(v, target) << endl;

    return 0;
}
