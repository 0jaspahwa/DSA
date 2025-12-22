class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        vector<int> dp(strs[0].size(),1);
        for(int i = 0 ; i < strs[0].size() ; i++){
            for(int j = 0 ; j < i ; j++){
                bool allValid = true;
                for(string s : strs){
                    if(s[j] > s[i]){
                        allValid = false;
                        break;
                    }
                }
                if(allValid) dp[i] = max(dp[i],dp[j]+1);
            }
        }
        return (strs[0].length() - (*max_element(dp.begin(),dp.end())));
    }
};