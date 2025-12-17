class Solution {
public:
    vector<int> p;
    long long m = -1e14;
    long long dp[1003][503][3];

    long long f(int i, int k, int s) {
        if (i == p.size()) return s == 0 ? 0 : m;
        if (dp[i][k][s] != -1) return dp[i][k][s];

        long long v = p[i];
        long long ans = m;

        ans = max(ans, f(i + 1, k, s)); //skiping the current day

        if (s == 0) {
            ans = max(ans, f(i + 1, k, 1) - v); //buy
            ans = max(ans, f(i + 1, k, 2) + v); //sell
        }
        else if (k >= 1) {// rem tractions
            if (s == 1) ans = max(ans, f(i + 1, k - 1, 0) + v); //sell to close
            else ans = max(ans, f(i + 1, k - 1, 0) - v); // buy to cover
        }
        return dp[i][k][s] = ans;
    }

    long long maximumProfit(vector<int>& pr, int k) {
        memset(dp, -1, sizeof(dp));
        p = pr;
        return f(0, k, 0);
    }
};