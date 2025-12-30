class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        int j=0;
        
        long long prefixsum =0;
        long long result = LLONG_MIN;;
            
        vector<int> suffixmin(n);
        suffixmin[n-1] = nums[n-1];
        for(int i= n-2; i>=0; i--){
            suffixmin[i] = min(nums[i+1],suffixmin[i+1]);
        }
        while(j < n-1){
            prefixsum += nums[j];    
            long long ans = prefixsum - suffixmin[j];
            result = max(ans,result);
            j++;
        }
        return result;
    }
};