class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(auto i : nums){
            mp[i]++;
        }
        for(auto &pair : mp){
            if(pair.second > 1){
                return pair.first;
            }
        }
        return 0;
    }
};