class Solution {
public:
    vector<vector<int>> result;

    void solve(int idx, vector<int>& nums){
        int n = nums.size();
        if(idx == n){
            result.push_back(nums);
            return;
        }

        for(int i = idx; i<n; i++){ // if we start i from 0, we will get same results in recursion tree
            swap(nums[i], nums[idx]); // do
            solve(idx + 1, nums); // explore
            swap(nums[i], nums[idx]); // undo
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        solve(0,nums);
        return result;
    }
};