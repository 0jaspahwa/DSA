class Solution {
public:
    typedef long long ll;
    int countPairs(vector<int>& del) {
        int n = del.size();
        unordered_map<int, int> mp;
        ll count =0;
        int M = 1e9 + 7;

        for(auto &x : del){
            for(int i=0; i<=21; i++){
                int power = 1 << i;
                int target = power - x;

                if(mp.count(target)){
                    count += mp[target];
                }
            } 
            mp[x]++;
        }
        return count % M;
        
    }
};