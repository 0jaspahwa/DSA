class Solution {
public:
    bool ischeck(vector<int>& time, int totalTrips, long long mid){
        int n = time.size();
        long long trips=0;
        for(int i=0; i<n; i++){
            trips  += mid/time[i];
        }
        if(trips >= totalTrips) return true;
        return trips >= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n =time.size();
        long long l=1;
        long long minn = *min_element(time.begin(),time.end());
        long long r= minn * totalTrips;
        long long ans=0;
        while(l <= r){
            long long mid = l + (r-l)/2;
            
            if(ischeck(time,totalTrips,mid)){
                ans = mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
            
        }
        return ans;
    }
};