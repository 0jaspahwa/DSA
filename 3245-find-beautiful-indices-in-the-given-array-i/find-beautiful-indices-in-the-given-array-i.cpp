class Solution {
public:
    vector<int> compLPS(const string &pattern){
        int n = pattern.length();
        vector<int>lps(n,0);
        for(int i=1; i<n; i++){
            int prev_idx = lps[i-1];
            while(prev_idx > 0 && pattern[i] != pattern[prev_idx]){
                prev_idx = lps[prev_idx-1];
            }
            lps[i] = prev_idx +(pattern[i] == pattern[prev_idx] ? 1: 0); 
        }
        return lps;
    }

    vector<int> KMP(const string &text, const string &pattern){
        string combined = pattern + "#" + text;
        vector<int> lps = compLPS(combined);
        vector<int> occurrences;
        for(int i = pattern.size(); i<lps.size(); i++){
            if(lps[i] == pattern.size()){
                int startidx = i-2*pattern.size();
                if(startidx >= 0){
                    occurrences.push_back(startidx);
                }
            }
        }
        return occurrences;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.length();
        vector<int> i_indices = KMP(s, a);
        vector<int> j_indices = KMP(s, b);
        vector<int> result;

        // --- BUG 3 FIX ---
        // The original function was incomplete. This is the logic to find beautiful indices.
        // We use a two-pointer approach for efficiency, since both index vectors are sorted.
        if (i_indices.empty() || j_indices.empty()) {
            return {}; // No beautiful indices if one of the patterns is not found.
        }

        int j_ptr = 0;
        for (int i : i_indices) {
            // Advance the j_ptr to the window of possible matches for the current i.
            // We move j_ptr forward as long as j is too small (j < i - k).
            while (j_ptr < j_indices.size() && j_indices[j_ptr] < i - k) {
                j_ptr++;
            }

            // Check if the current j_ptr points to a valid j.
            // A valid j must exist (j_ptr not out of bounds) and be within the k-distance (j <= i + k).
            if (j_ptr < j_indices.size() && abs(i - j_indices[j_ptr]) <= k) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};