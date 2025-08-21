class Solution {
public:
    int bsearch(int target,int k,vector<int>& nums,vector<long>& prefixsum){
         int t = nums[target];
         int l=0;
         int r=target;
         int result = target;
         while(l<=r){
            int mid = l+(r-l)/2;
            long count = target-mid+1;
            long windowsum = count*t;
            long orignal = prefixsum[target] - prefixsum[mid] + nums[mid];
            int ops = windowsum - orignal;

            if(ops >k){
                l=mid+1;
            }
            else{
                result = mid;
                r=mid-1;
            }
        }
        return target-result+1;   
    }
    int maxFrequency(vector<int>& nums, int k) {
       int n= nums.size();
       sort(nums.begin(),nums.end()); 

       vector<long> prefixsum(n);
       prefixsum[0] = nums[0];
       for(int i=1; i<n; i++){
            prefixsum[i] = prefixsum[i-1] + nums[i];
       }

       int result = 0;

       for(int target=0; target<n; target++){
            result = max(result,bsearch(target,k,nums,prefixsum));
       }
       return result;
    }
};