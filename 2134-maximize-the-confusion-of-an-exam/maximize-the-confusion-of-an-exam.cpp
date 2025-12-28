class Solution {
public:
    int solve(string &anskey, int k, char target){
        int n =anskey.size();
        int i=0;
        int j=0;
        int max_len =0;
        int flip =0;

        while(j<n){
            if(anskey[j] != target){
                flip++;
            }
            while(flip > k){
                if(anskey[i] != target){
                    flip--;
                }
                i++;
            }
            max_len = max(max_len, j-i+1);
            j++;
        }
        return max_len;
    }
    int maxConsecutiveAnswers(string anskey, int k) {
        return max(solve(anskey,k,'T'),solve(anskey,k,'F'));
    }
};