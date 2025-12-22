class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex;
        vector<vector<int>> result(n+1);
            
            for(int i=0; i<n+1; i++){
                result[i] = vector<int>(i+1,1);
                for(int j=1; j<i; j++){
                    result[i][j] = result[i-1][j] + result[i-1][j-1];
                }
            }
        return result[n];    
    }
};