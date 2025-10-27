class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> result;
        int n = nums.size();
        for(auto& num : nums){
            mp[num]++;
        }

        for(auto num : nums){
            if(mp[num] == 1 && mp.find(num -1) == mp.end() && mp.find(num+1) == mp.end()){
                result.push_back(num);
            }
        }
        return result;

    }
};