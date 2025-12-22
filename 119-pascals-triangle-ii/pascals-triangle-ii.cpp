class Solution {
public:
    typedef long long ll;
    vector<int> getRow(int rowIndex) {
        int n = rowIndex;
        vector<int> result;
        result.push_back(1);
        for(int i=1; i<=n; i++){
            ll element = (ll)(result[i-1]) * (n-i+1) / i;
            result.push_back(element);
        }
        return result;
    }
};