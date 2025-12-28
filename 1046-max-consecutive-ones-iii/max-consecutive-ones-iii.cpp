class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0;
        int j=0;
        int flip =0;
        int max_l =0;
        while(j<n){
            if(nums[j] != 1){
                flip++;
            }
            while(flip > k){
                if(nums[i] != 1){
                    flip--;
                }
                i++;
            }
            max_l = max(max_l,j-i+1);
            j++;
        }
        return max_l;
    }
};