class Solution {
public:
    typedef long long ll;
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
    
        ll allcandy = accumulate(candies.begin(),candies.end(),0ll);
        ll maxx= allcandy/k;
        ll ans =0;
        ll l=1;
        ll r= maxx;
        while(l<=r){
            ll mid = l + (r-l)/2;
            ll totalchild=0;
            for(int i : candies){
                totalchild += i/mid;
            }
            if(totalchild >= k){
                ans = mid;
                l = mid+1;
            }
            else{
                r=mid-1;
            }

        }
        return ans;
        
    }
};