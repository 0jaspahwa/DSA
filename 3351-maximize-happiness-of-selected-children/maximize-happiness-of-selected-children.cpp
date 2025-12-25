class Solution {
public:
    typedef long long ll;
    long long maximumHappinessSum(vector<int>& hap, int k) {
        ll cnt=0;
        ll ans=0;
        int n = hap.size();
        sort(hap.begin(),hap.end(),greater<int>());
        for(int i=0; i<n; i++){
            if(k>0 && hap[i] - cnt > 0){
                ans += hap[i] - cnt;
                cnt++;
                k--;
            }
        }
        return ans;
    }
};