class Solution {
public:
    bool ispossible( vector<int> & nums, int maxOperations, int mid){
        long long totalcount =0;
        for(auto &num : nums){
            
            int ops = num / mid;
            
            if(num % mid == 0){
                ops -= 1;
            }
            totalcount += ops;
        }
        if(totalcount <= maxOperations) {
            return true;
        }    
        else{
            return false;
        }
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int l =1;
        int r = *max_element(nums.begin(), nums.end());
        int result = r;

        while(l <= r){
            int mid = l +(r-l)/2;
            if(ispossible(nums, maxOperations, mid) == true){
                result = mid;
                r= mid-1;
            }
            else{
                l= mid+1;
            }
        }
        return result;
    }
};