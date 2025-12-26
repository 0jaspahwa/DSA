class Solution {
public:
    bool isvalid(vector<int>& nums,int midmax,int n){
        long long buffer =0;
        vector<long long> arr(nums.begin(),nums.end());
        for(int i=0; i<n-1; i++){
            if(arr[i] > midmax){
                return false;
            }
            buffer = midmax - arr[i];
            arr[i+1] = arr[i+1] - buffer;
        }
        return arr[n-1] <= midmax;
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