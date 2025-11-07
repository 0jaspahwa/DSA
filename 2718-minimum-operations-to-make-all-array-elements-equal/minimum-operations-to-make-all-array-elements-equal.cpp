class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> result;
        vector<long long> prefix_s(n+1,0);
        for(int i=0; i<n; i++){
            prefix_s[i+1] = prefix_s[i] + nums[i];
        }

        for(auto &q_val : queries){
            long long q = (long long)q_val;
            auto it  = lower_bound(nums.begin(),nums.end(),q);
            int idx = it - nums.begin();
            long long left = (q*idx) - prefix_s[idx];
            long long right = (prefix_s[n] - prefix_s[idx])- (q * (n-idx)); 

            result.push_back(left + right);
        }
        return result;
    }
};