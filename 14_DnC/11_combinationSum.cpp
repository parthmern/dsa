#include <iostream>
#include <vector>
using namespace std;

void findCombinations(int sum, vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& result, int indexNow) {

    // bc
    if( sum == target ){
        cout << " matched target" << endl;
        result.push_back(current);  
        return ;
    }

    if( sum > target ){
        return;
    }

    // rr
    for( int i=indexNow; i<candidates.size(); i++){
        current.push_back(candidates[i]);
        findCombinations(sum+candidates[i], candidates, target, current, result, i);
        current.pop_back();
    }

    
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current;

    // Start backtracking
    findCombinations(0, candidates, target, current, result, 0);

    return result;
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = combinationSum(candidates, target);

    cout << "Combinations that sum to " << target << " are: " << endl;
    for (const auto& combination : result) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
