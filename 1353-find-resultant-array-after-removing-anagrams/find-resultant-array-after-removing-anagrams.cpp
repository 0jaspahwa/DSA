class Solution {
public:
    bool check(string a, string b){
        if(a.length() != b.length()) return false;

        unordered_map<char,int> mp;
        for(char ch: a){
            mp[ch]++;
        }
        for(char ch : b){
            mp[ch]--;
        }

        for(auto count : mp){
            if(count.second != 0){
                return false;
            }
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        if (words.empty()) {
            return {};
        }
        vector<string> ans;
        ans.push_back(words[0]);
        for(int i=1; i<n; i++){
            
            if(check(ans.back(),words[i]) == false){
                ans.push_back(words[i]);
            }
        }
        return ans;
        
    }
};