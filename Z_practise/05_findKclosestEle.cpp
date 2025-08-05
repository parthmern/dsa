// https://leetcode.com/problems/find-k-closest-elements/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int low = 0;
        int high = arr.size() - 1;

        while(true){


             if( abs(low-high) < k ){
                break;
            }

            int diffAtLow = abs(x - arr[low]);
            int diffAtHigh = abs(x - arr[high]);

            if(diffAtLow > diffAtHigh){
                low++;
            }else{
                high--;
            }

        }

        vector<int> ans ;
        while(low<=high){
            ans.push_back(arr[low]);
            low++;
        }

        return ans;


    }
};