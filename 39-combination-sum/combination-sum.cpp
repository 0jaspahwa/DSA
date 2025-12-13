class Solution {
public:
    vector<vector<int>> result;

    void solve(int idx,vector<int> &temp, vector<int>& candidates, int target){
        int n = candidates.size();
        if(target == 0){
            result.push_back(temp);
            return;
        }

        for(int i=idx; i<n; i++){ 
            // [2] → [3] → [2]   ❌ reordered. [2] → [2] → [3]   ✅ valid
            // [3] → ❌ cannot go back to 2


            if(candidates[i] <= target){
                temp.push_back(candidates[i]);
                solve(i,temp,candidates,target - candidates[i]);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> temp;
        solve(0,temp,candidates,target);

        return result;
    }
};