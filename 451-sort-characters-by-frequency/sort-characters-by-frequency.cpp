class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto& ch : s){
            mp[ch]++;
        }
        priority_queue<pair<int, char>> pq;
        for(auto& pair : mp){
            pq.push({pair.second, pair.first});
        }

        string result ="";
    
        while(!pq.empty()){
            pair<int, char> top_pair = pq.top();
            pq.pop();
            int freq = top_pair.first;
            int c = top_pair.second;

            result.append(string(freq,c));
        }
        return result;
    }
};