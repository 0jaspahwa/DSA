class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        if (n <= 1) return 0;
        int m = strs[0].length();
        
        int del = 0;
        bitset<1000> sorted_mask; 

        for (int j = 0; j < m; ++j) {
            bool keep = true;
            for (int i = 0; i < n - 1; ++i) {
            
                if (!sorted_mask[i] && strs[i][j] > strs[i+1][j]) {
                    keep = false;
                    break;
                }
            }

            if (!keep) {
                del++;
            } else {
                
                for (int i = 0; i < n - 1; ++i) {
                    if (strs[i][j] < strs[i+1][j]) {
                        sorted_mask.set(i);
                    }
                }
            }
        }
        return del;
    }
};