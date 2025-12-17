class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int currentsum =0;
        int count =0;
        mp[0] =1;
        for(auto &num : nums){
            currentsum += num;

            int need = currentsum - k;
            if(mp.find(need) != mp.end()){
                count += mp[need];
            }

            mp[currentsum]++;
        }
        return count;
    }
};