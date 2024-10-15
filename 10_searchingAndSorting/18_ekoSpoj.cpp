#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


bool isPossible(vector<long long int> trees, long long int totalMeter, long long int mid){

    long long int woodCollection = 0;

    for(int i=0; i<trees.size(); i++){
        if(trees[i]>mid){
            woodCollection = woodCollection + (trees[i]-mid);
        }
    }

    return woodCollection>=totalMeter ? true : false ;
}

long long int maxSawBladeHeight(vector<long long int> trees, long long int m){

    long long int start=0, end, ans = -1;
    end = *max_element( trees.begin(), trees.end() );

    while(start<=end){
        long long int mid = start + (end-start)/2;

        if( isPossible(trees, m, mid) ){
            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }

    }

    return ans;

}

int main(){

    vector<long long int> arr{20,15,10,17};
    long long int totalMeter = 7;

    long long int totalTrees = 4;

    cout << maxSawBladeHeight( arr, totalMeter );





    return 0;
}

