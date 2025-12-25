class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        int ans=-1;
        int n = dist.size();
        int l=1;
        int r = 10000000;
        while(l<=r){
            int mid = l + (r-l)/2;
            double value =0;
            for(int i=0; i<n-1; i++){
                value += ceil((double)dist[i]/mid);
            }
            value += (double)dist[n-1]/mid;
            
            if(value > hour){
                l=mid+1;
            }
            else{
                ans = mid;
                r=mid-1;
            }
        }
        return ans; 
    }
};