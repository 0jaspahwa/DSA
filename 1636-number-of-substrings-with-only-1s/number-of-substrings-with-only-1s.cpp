class Solution {
public:
    int numSub(string s) {
        int n = s.length();

        long long sum =0;
        long long total =0;
        int  p =0;
        int M = 1e9 + 7;
        while( p < n){
            if(s[p] == '0'){
                ++p;
                continue;
            }
            long long count =0;
            while(p < n && s[p] == '1'){
                ++count;
                ++p;
            }
            sum = ((count + 1) * count) / 2;
            total = (total + sum) % M;

        }
        return total;
    }
};