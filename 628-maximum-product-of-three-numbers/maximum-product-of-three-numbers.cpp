class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        long long maxx =1;
        long long minn =1;
        int result =1;

        int onemax = nums[n-1];
        int secmax = nums[n-2];
        int thirdmax = nums[n-3];

        int onemin = nums[0];
        int secmin = nums[1];
        int thirdmin = nums[2];

        maxx = (onemax * secmax * thirdmax);
        minn = (onemin * secmin * onemax);
        result = max(maxx,minn);
        return result;
    }
    
};