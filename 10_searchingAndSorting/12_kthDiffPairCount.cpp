#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int countedKthDiff(vector<int> nums, int k){

    // sorted array
    sort(nums.begin(), nums.end());

    int i = 0;
    int j = 1;

    set<pair<int,int>> ans;

    while(j < nums.size()){

        int diff = abs(nums[i]-nums[j]);

        if(diff == k){
            cout << "got" << nums[i] << nums[j] << endl;
            ans.insert( {nums[i],nums[j]} );

            i++;
            j++;
            
           
        }
        else if(diff > k){
            j++;
        }
        else {
            i++;
        }

        if(i==j){
            j++;
        }

    }

    return ans.size();

}

int countedKthDiffBs(vector<int> nums, int start, int targrtEle){
    
    int end = nums.size() - 1;

    while(start <= end){
        int mid = (start+end)/2;

        if(nums[mid] == targrtEle){
            return mid;
        }
        else if(targrtEle > nums[mid]){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }

    return -1;

}


int main(){

    vector<int> v{3,1,4,1,5};

    int k = 2;

    cout << countedKthDiff(v, k);

    // -------------------------
    set<pair<int,int>> ans;

    // sorted array
    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++){

        int target = v[i]+k;

        if(countedKthDiffBs(v, i+1, target) != -1 ){
            cout << "new ->" << v[i] << v[i] + k << endl;
            ans.insert( {v[i],v[i] + k } );
        }

    }



    return 0;
}