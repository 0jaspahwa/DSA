class Solution {
public:
    vector<int> getRow(int rowIndex) {
        //optimized we are using just one before elements to count the result
        int n = rowIndex;
        vector<int> prev;
            
            for(int i=0; i<n+1; i++){
                vector<int> curr(i+1,1);
                for(int j=1; j<i; j++){
                    curr[j] = prev[j] + prev[j-1];
                }
                prev = curr;
            }
        return prev;    
    }
};