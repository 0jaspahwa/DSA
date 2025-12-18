class Solution {
public:
    typedef long long ll;
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        ll actualprofit =0;

        vector<ll> profit(n);
        for(int i=0; i<n; i++){
            profit[i] = (ll) prices[i] * strategy[i];
            actualprofit += profit[i];
        }

        ll org =0;
        ll modified =0;
        ll maxgain=0;

        int i=0;
        int j=0;
        while(j < n){
            org += profit[j];
            if(j-i+1 > k/2){
                modified += prices[j];
            } 

            if(j-i+1 > k){
                org -= profit[i];
                modified -= prices[i+k/2];
                i++; 
            }

            if(j-i+1 == k){
                maxgain = max(maxgain, modified - org);
            }
            j++;
            
        }
        return actualprofit + maxgain;

    }
};