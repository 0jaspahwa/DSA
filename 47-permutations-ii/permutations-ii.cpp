class Solution {
public:
    vector<vector<int>> result;
    

    void solve(int idx, vector<int>& nums){
        int n = nums.size();
        if(idx == n){
            result.push_back(nums);
            return;
        }
        unordered_set<int> used;
        for(int i=idx; i<n; i++){
            if (used.count(nums[i])) continue;

            used.insert(nums[i]);
            swap(nums[i],nums[idx]);
            solve(idx + 1,nums);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        solve(0,nums);
        return result;
    }
};