class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        long long prev=1;
        int count =0;
        int l=0;

        for(int r = 0; r<n; r++){
            prev = prev * nums[r];

            while(prev >= k && l <=r){
                prev = prev / nums[l];
                l++;
            }
            count += (r-l)+1;
        }
        return count;
    }
};