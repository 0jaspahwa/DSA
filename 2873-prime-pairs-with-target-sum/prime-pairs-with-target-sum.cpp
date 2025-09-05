class Solution {
public:
    
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> isprime(n+1,true);
            isprime[0] = isprime[1] = false;
            for(int i=2; i*i<=n; i++){
                if(isprime[i] == true){
                    for(int j=i*i; j<=n; j+=i){
                        isprime[j] = false;
                    }
                }
            }
        
        vector<vector<int>> result;

        for(int x=2; x<=n/2; x++){
            int y = n-x;
            if(isprime[y] && isprime[x]){
                result.push_back({x,y});
            }
        }
        return result;
    }
};