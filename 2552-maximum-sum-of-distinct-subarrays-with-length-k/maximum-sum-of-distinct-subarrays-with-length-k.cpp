class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n =nums.size();
        unordered_map<int,int> mp;
        int i=0;
        int j=0;
        long long sum =0;
        long long ans =0;
        while(j<n){
            sum += nums[j];
            mp[nums[j]]++;
            while(j-i+1 > k){
                sum -= nums[i];
                mp[nums[i]]--;
                i++;
            }
            while(mp[nums[j]] > 1){
                sum -= nums[i];
                mp[nums[i]]--;
                i++;
            }

            if(j-i+1 == k){
                ans = max(ans,sum);
            }
            j++;
            
        }
        return ans;
    }
};