class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string ans ="";
        int count =0;

        while(ans.size() < b.size()){
            ans = ans + a;
            count++;
        }
        if(rabinKarp(ans,b)){
            return count;
        }
        ans += a;
        count++;
        if(rabinKarp(ans,b)){
            return count;
        }
        return -1;
    }
private:
    bool rabinKarp(const string &text, const string &pattern) {
        int n = text.size();
        int m = pattern.size();
        if (m > n) return false;

        // Use long long for hashes and a better prime MOD
        const int radix = 26;
        const long long MOD = 1e+7; 
        
        long long dpower = 1;
        for (int i = 0; i < m - 1; i++) {
            dpower = (dpower * radix) % MOD;
        }
        
        long long patternhash = 0;
        long long texthash = 0;
        
        // Calculate initial hash using character mapping ('a' -> 0, etc.)
        for (int i = 0; i < m; i++) {
            patternhash = (patternhash * radix + (pattern[i] - 'a')) % MOD;
            texthash = (texthash * radix + (text[i] - 'a')) % MOD;
        }

        // Sliding window
        for (int i = 0; i <= n - m; i++) {
            // Check for match only if hashes are equal
            if (patternhash == texthash) {
                if (text.substr(i, m) == pattern) {
                    return true;
                }
            }

            // Roll the hash for the next window
            if (i < n - m) {
                // 1. Remove leading character
                texthash = texthash - ((text[i] - 'a') * dpower) % MOD;
                // 2. Add MOD to handle potential negative result
                if (texthash < 0) {
                    texthash += MOD;
                }
                // 3. Shift hash and add trailing character
                texthash = (texthash * radix + (text[i + m] - 'a')) % MOD;
            }
        }
        
        return false;
    }
};