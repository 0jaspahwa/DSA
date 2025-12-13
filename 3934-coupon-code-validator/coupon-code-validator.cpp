class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n=code.size();
        auto ok = [&](string &s)->bool{
            if(!s.length()) return false;
            for(char c: s){
                if(isalnum(c) || c=='_') continue;
                else return false;
            }
            return true;
        };
        vector<int> indices = {};
        for(int i=0; i<n; i++){
            if(ok(code[i]) && 
            (businessLine[i]=="electronics" ||
             businessLine[i]=="grocery" ||
             businessLine[i]=="pharmacy" ||
             businessLine[i]=="restaurant") && 
             isActive[i]){
                indices.push_back(i);
            }
        }
        sort(indices.begin(), indices.end(), [&](int a, int b)->bool{
            return businessLine[a]==businessLine[b] ? code[a]<code[b] : businessLine[a]<businessLine[b];
        });
        vector<string> codes={};
        for(auto i: indices){
            codes.push_back(code[i]);
        }
        return codes;
    }
};