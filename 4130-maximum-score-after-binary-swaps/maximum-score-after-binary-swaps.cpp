class Solution {
public:
    typedef long long ll;
    long long maximumScore(vector<int>& nums, string s) {
        int n= nums.size();
        priority_queue<ll> q;
        ll ans =0;
        for(int i=0; i<n; i++){
            q.push(nums[i]);
            if(s[i] == '1'){
                int a = q.top();
                q.pop();
                ans += a;
            }
        }
        return ans;
    }
};