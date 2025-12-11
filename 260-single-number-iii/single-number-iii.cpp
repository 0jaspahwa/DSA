class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        vector<int> result;

        for(auto &num : nums){
            mp[num]++;
        }

        for(auto &i : mp){
            if(i.second == 1){
                result.push_back(i.first);
            }
        }
        return result;
    }
};