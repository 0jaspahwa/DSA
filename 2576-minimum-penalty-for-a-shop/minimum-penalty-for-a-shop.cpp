class Solution {
public:
    int bestClosingTime(string cust) {
        int n = cust.size();
        vector<int> prefix_n(n+1,0);
        vector<int> suffix_y(n+1,0);
        for(int i=0; i<n; i++){
            prefix_n[i+1] = prefix_n[i];
            if(cust[i] == 'N'){
                prefix_n[i+1] += 1;
            }
        }
        for(int i=n-1; i>=0; i--){
            suffix_y[i] = suffix_y[i+1]; 
            if(cust[i] == 'Y'){
                suffix_y[i] += 1;
            }
        }

        int min_p = INT_MAX;
        int min_h = INT_MAX;
        for(int i=0; i<=n; i++){
            int penalty = suffix_y[i] + prefix_n[i];
            if(penalty < min_p){
                min_p = penalty;
                min_h = i;
            }
        }
        return min_h;
    }
};