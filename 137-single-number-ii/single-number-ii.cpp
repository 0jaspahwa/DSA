class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n =nums.size();
        unordered_map<int,int> mp;

        for(auto &num : nums){
            mp[num]++;
        }

        for(auto &i : mp){
            if(i.second == 1){
                return i.first;
            }
        }
        return -1;
    }
};