class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        int maxsum = dp[0];

        for(int i=1; i<n; i++){
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
            maxsum = max(maxsum,dp[i]);
        }
        return maxsum;
    }
};