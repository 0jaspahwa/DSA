class Solution {
public:
    bool abc(char ch){
        return ch == 'a' || ch == 'b' || ch == 'c';
    }

    int numberOfSubstrings(string s) {
        int n = s.length();
        unordered_map<char,int> mp;
        int i=0;
        int j=0;
        long long count =0;

        while( j<n){
            char ch = s[j];
            if(abc(ch)){
                mp[ch]++;
            }
            while(mp.size() == 3){
                count += (n-j);
                char ch = s[i];
                mp[ch]--;
                if(mp[ch] == 0){
                    mp.erase(ch);
                }
                i++;
            }
            j++;
        }
        return count;

    }
};