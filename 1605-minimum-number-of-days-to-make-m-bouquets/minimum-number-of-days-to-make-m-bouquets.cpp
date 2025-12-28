class Solution {
public:
    bool ischeck(vector<int>& day, int m, int k, int mid){
        int n = day.size();
        int i = 0;
        int guldasta =0;
        int cnt =0;
        for(int j=0; j<n; j++){
            if(day[j] <= mid){
                cnt++;
                if(cnt == k){
                    guldasta++;
                    cnt =0;
                }
            }
            else{
                cnt =0;
            }    
        }
        return guldasta >= m;
    }
    int minDays(vector<int>& day, int m, int k) {
        int n = day.size();
        if (1LL * m * k > n) return -1;
        int l=*min_element(day.begin(),day.end());;
        int r= *max_element(day.begin(),day.end());
        int ans =0;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(ischeck(day,m,k,mid)){
                ans = mid;
                r = mid -1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};