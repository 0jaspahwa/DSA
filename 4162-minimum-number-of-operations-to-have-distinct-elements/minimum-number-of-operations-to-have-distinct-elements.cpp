class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(); 
        unordered_set<int> s;
        int i=0;
        for(i=n-1; i>=0; i--){
            if(s.count(nums[i])) break;
            s.insert(nums[i]);
        }
        return (i+3)/3;
    }
};