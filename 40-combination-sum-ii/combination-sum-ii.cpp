class Solution {
public:
    vector<vector<int>> result;

    void solve(int idx, vector<int>& temp,vector<int>& candidates, int target){
        
        int n = candidates.size();
        if(target == 0){
            result.push_back(temp);
            return;
        }
        
        for(int i=idx; i<n; i++){
            if(i > idx && candidates[i] == candidates[i-1]){
            continue;
            }
            if(candidates[i] > target){
                break;
            }
            if(candidates[i] <= target){
                temp.push_back(candidates[i]);
                solve(i+1,temp,candidates,target - candidates[i]);
                temp.pop_back();
            }    
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        solve(0,temp,candidates,target);
        return result;
    }
};