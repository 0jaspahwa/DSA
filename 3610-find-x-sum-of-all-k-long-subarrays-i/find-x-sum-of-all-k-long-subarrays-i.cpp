class Solution {
public:
    int find(unordered_map<int,int> &mp, int x){
        vector<vector<int>>ans;
        for(auto i: mp){
            ans.push_back({i.second,i.first});
        }
        sort(ans.rbegin(),ans.rend());

        int xsum =0;
        int m =ans.size();

        for(int i=0; i<min(x,m); i++){
            xsum += ans[i][1] * ans[i][0];
        }
        return xsum;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int,int> mp;
        vector<int> result;
        int n = nums.size();
    
        for(int i=0; i<k;i++){
            mp[nums[i]]++;
        }

        result.push_back(find(mp,x));

        for(int i=k; i<n; i++){
            mp[nums[i-k]]--;
            mp[nums[i]]++;

            if(mp[nums[i-k]] == 0){
                mp.erase(nums[i-k]);
            }
            result.push_back(find(mp,x)); 
        }
        return result;
    }
};