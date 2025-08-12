class Solution {
public:

    int minn = INT_MAX;

    void solve(vector<int>& arr, int target, int count){

        if( target == 0 ){
            cout << "ans" << count << endl;
            minn = min(minn , count);
            return;
        }
        
        if(target < 0 ){
            return ;
        }

        for( int i=0; i<arr.size(); i++ ){
            solve(arr, target-arr[i], count+1);
        }

    }



    int coinChange(vector<int>& arr, int target) {
        solve(arr, target, 0);
        return minn == INT_MAX ? -1 : minn;

    }
        

        
};