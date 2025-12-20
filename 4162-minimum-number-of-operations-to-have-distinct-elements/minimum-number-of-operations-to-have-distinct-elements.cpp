class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> mp;
        int cnt=0;
        for(int i= n-1; i>=0; i--){
            if(mp.count(nums[i])){
                break;
            }
            mp.insert(nums[i]);
            cnt++;
        }
        return ceil((double)(n-cnt)/3);
    }
};