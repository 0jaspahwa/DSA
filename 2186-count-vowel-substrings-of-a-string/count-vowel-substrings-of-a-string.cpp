class Solution {
public:
    bool isvowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int countVowelSubstrings(string word) {
        long long count = 0;
        int n = word.length();
        int i = 0; // Start of the minimal valid window
        int k = 0; // Start of the current vowel-only segment
        unordered_map<char, int> mp;

        for (int j = 0; j < n; j++) {
            char ch = word[j];

            if (isvowel(ch)) {
                mp[ch]++;
                while (mp.size() == 5 && mp[word[i]] > 1) {
                    mp[word[i]]--;
                    i++;
                }
                if (mp.size() == 5) {
                    count += (i - k + 1);
                }
            } else {
                
                mp.clear();
                k = j + 1; 
                i = j + 1; 
            }
        }
        return count;
    }
};