class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int,int> mp;
        for(auto &num : nums){
            mp[num]++;
        }
        for(auto const& pair : mp){
            if(pair.second > 1){
                ans.push_back(pair.first);
            }
        }
        return ans;
    }
};