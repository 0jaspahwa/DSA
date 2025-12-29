class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n =nums.size();
        int i=0;
        int j=0;
        long long sum =0;
        long long result =0;
        unordered_map<int,int> mp;
        int cnt =0;

        while(j<n){
            sum += nums[j];
            mp[nums[j]]++;
            if(mp[nums[j]] == 1){
                cnt++;
            }
            
            while(j-i+1 >k){
                sum -= nums[i];
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    cnt--;
                }
                i++;
            }
            if(cnt >= m && j-i+1 == k){
                result = max(result,sum);
            }
            j++;
        }
        return result;
    }
};