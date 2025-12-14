class Solution {
public:
    vector<vector<int>> result;
    

    void solve(int idx, vector<int>& temp, vector<int>& nums){
        int n= nums.size();
        if(idx == n){
            result.push_back(temp);
            return;
        }

    
            solve(idx+1,temp,nums);//exclude

            temp.push_back(nums[idx]);// include
            solve(idx+1,temp,nums);
            temp.pop_back();// backtrack
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> temp;
        solve(0,temp,nums);
        return result;
    }
};