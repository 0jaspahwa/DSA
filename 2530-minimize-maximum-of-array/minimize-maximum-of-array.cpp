class Solution {
public:
    bool isvalid(vector<int>& nums,int midmax,int n){
        long long currsum =0;
        for(int i=0; i<n; i++){
            currsum += nums[i];
            if(currsum > (long long)midmax * (i+1)){
                return false;
            }
        }    
        return true;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        int l=nums[0];
        int r = *max_element(nums.begin(),nums.end());
        int result =0;
        while(l <= r){
            int midmax = l +(r-l)/2;
            if(isvalid(nums,midmax,n)){
                result=midmax;
                r=midmax-1;
            }
            else{
                l=midmax+1;
            }
        }
        return result;;
    }
};