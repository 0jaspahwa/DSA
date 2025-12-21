class Solution {
public:
int t[100001][3][4];
    int solve(int i, int currRem, vector<int>& nums, int k){
        int n=nums.size();
        int ans=0;
        if(k==0){
            return (currRem == 0) ? 0 :-1e9;
        }
        if(i == n){
            return -1e9;
        }
        if(t[i][currRem][k] != -1) return t[i][currRem][k]; 

        int include = -1e9;
        int res = solve(i+1,(currRem + nums[i]) % 3,nums,k-1);
        if(res != -1e9){
            include = nums[i] + res;
        }
        int exclude = solve(i+1,currRem,nums,k);
        
        return t[i][currRem][k] = max(include, exclude);

    }
    int maximumSum(vector<int>& nums) {
        int n =nums.size();
        memset(t,-1,sizeof(t));
        int result = solve(0,0,nums,3);
        return (result < 0) ? 0 : result;
    }
};