class Solution {
public:
    long long ans(vector<int>& nums, int target){
        long long value = 0;
        for(auto &i : nums){
            value += 1LL *abs(i - target);
        }
        return value;

    }
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(),nums.end());

        
        long long result = INT_MAX;
        while(l<= r){
            int mid = l +(r-l) /2;
            int cost1 = ans(nums,mid);
            int cost2 = ans(nums,mid+1);
            result = min(cost1,cost2);

            if(cost2 > cost1){
                r= mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return result;
    }
};