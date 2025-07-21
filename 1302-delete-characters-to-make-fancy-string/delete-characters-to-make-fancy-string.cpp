class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        int cons = 0;
        for(int i =0; i<s.length(); i++){
            if(i>=2 && s[i] == s[i-1] && s[i-1] == s[i-2]){
                continue;
            }
            ans += s[i];
        }
        return ans;
        
    }
};