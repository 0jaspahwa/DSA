class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int curmax = nums[0];
        int curmin = nums[0];
        int result = nums[0];

        for(int i=1; i<n; i++){
            int num = nums[i];
            if(num < 0 ){
                swap(curmax,curmin);
            }
            curmax = max(num, curmax * num);
            curmin = min(num, curmin * num);
            result = max(result,curmax);
        }
        return result;
    }
};