class Solution {
public:
    int dp[40001][3];
    int solve(vector<int>& nums, int i, int rem){
        int n= nums.size();
        if(i >= n){
            if(rem == 0) return 0;
            else{
                return INT_MIN;
            }
        }
        if(dp[i][rem] != -1){
            return dp[i][rem];
        }

        int yes = nums[i] + solve(nums,i+1,(rem+nums[i]) % 3);
        int no = solve(nums,i+1,rem);
        return dp[i][rem] = max(yes,no);

    }
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,0);
    }
};