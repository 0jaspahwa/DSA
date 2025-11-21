class Solution {
public:
    int countHomogenous(string s) {
        int M = 1e9 + 7;

        long long n = s.length();
        long long ans =0;
        long long l=0;
        long long r=0;

        while(r < n){
            while(r < n && s[r] == s[l]){
                r++;
            }
            long long len = r-l;
            ans += (len * (len+1) / 2) % M;
            l = r;
        }
        return ans;
    }
};