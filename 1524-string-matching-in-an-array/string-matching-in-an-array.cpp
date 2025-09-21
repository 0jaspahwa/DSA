class Solution {
public:
    vector<int> KMP(const string &s){
        vector<int> lps(s.size(),0);
            for(int i=1; i<lps.size(); i++){
                int prev_idx = lps[i-1];
                while(prev_idx >0 && s[i] != s[prev_idx] ){
                    prev_idx = lps[prev_idx-1];
                }
                lps[i] = prev_idx + (s[i] == s[prev_idx] ? 1:0);
            }
            return lps;
    }
    bool issubstring(string needle, string haystack){
        string combined = needle + "#" + haystack;
        vector<int> lps = KMP(combined);
        for(int i=needle.size()+1; i<lps.size(); i++ ){
            if(lps[i] == needle.size()){
                return true;
            }
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
        vector<string> result;
        for(int i=0; i<words.size(); i++){
            for(int j=0; j<words.size(); j++){
                if(i != j && issubstring(words[i],words[j])){
                    result.push_back(words[i]);
                    break;
                }
            }
        }
        return result;
    }
};