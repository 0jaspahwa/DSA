class Solution {
public:
    bool ischeck(string &s, string &p, vector<int>& rem, int k){
        int n = s.size();
        vector<bool> removed(n,false);//(size,value)
        for(int i=0; i<k; i++){
            removed[rem[i]] = true;
        }

        int j=0;
        for(int i=0; i<n && j< p.size(); i++){
            if(removed[i]) continue;
            if(s[i] == p[j]){
                j++;
            }
        }
        return j == p.size();
    }
    int maximumRemovals(string s, string p, vector<int>& rem) {
        int n = s.size();
        int l=0;
        int r=rem.size();
        int ans =0;
        while(l<=r){
            int mid = (l+r)/2;
            if(ischeck(s,p,rem,mid)){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return ans;
    }
};