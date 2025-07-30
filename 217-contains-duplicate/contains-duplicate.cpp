class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i : nums){
            mp[i]++;
        }
        for(auto &pair : mp){
            if(pair.second > 1){
                return true;
            }
        }
        return false;
    }
};