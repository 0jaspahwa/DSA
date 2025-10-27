class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxel = *max_element(nums.begin(),nums.end()) + k;
        vector<int> freq(maxel+1,0);
        for(auto& num : nums){
            freq[num]++;
        }

        for(int i=1; i<=maxel; i++){
            freq[i] += freq[i-1]; 
        }
        int result =0;
        for(int target=0; target<=maxel; target++){
            if(freq[target] == 0) continue;
            int left = max(0,target - k);
            int right = min(maxel,target + k);
            int totalcount = freq[right] - (left > 0 ? freq[left-1] :0);
            int targetcount = freq[target] - (target > 0 ? freq[target-1] :0);
            int needed = totalcount - targetcount;
            int maxposs = targetcount + min(needed,numOperations);
            result = max(maxposs,result);
        }
        return result;
    }
};