class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups; //initialize map
        // create a key
        for(const string &s : strs){
            string key = s;
            sort(key.begin(), key.end());
            groups[key].push_back(s);
        }

        vector<vector<string>> result;
        for(auto const& [key,val] : groups){
            result.push_back(val);
        }
        return result;
    }
};