class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n= piles.size();
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        int ans =0;
        
        while(l <= r){
            long long totalh=0;
            int mid = l + (r-l)/2;
            for(int i=0; i<n; i++){
                totalh += ((piles[i] + mid -1) / mid);
            }
            if(totalh <= h){
                ans = mid;
                r = mid-1;     
            }
            else{    
                l=mid+1;
            }
        }
        return ans;
    }
};