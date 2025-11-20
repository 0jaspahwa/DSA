class Solution {
public:
    int numSub(string s) {
        int n = s.length();
        long long result =0;
        long long cnt =0;
        int M = 1e9 + 7;
        for(auto &i : s){
            if(i == '1'){
                cnt++;
                result = (result + cnt)  % M;
            }
            else{
                cnt= 0;
            }
        }
        return result;
    }
};