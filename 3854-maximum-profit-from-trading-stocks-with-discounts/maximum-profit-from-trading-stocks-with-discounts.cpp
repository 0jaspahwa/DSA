class Solution {
public:
    vector<vector<int>> adj;
    vector<vector<vector<int>>> dp; 
    vector<int> P, F;
    int B;

    void dfs(int u) {
        // profits from children: 
    
        vector<int> skip = {0}, buy = {0};

        for (int v : adj[u]) {
            dfs(v);
            // Merge child v's results into current
            auto merge = [&](vector<int>& curr, const vector<int>& child) {
                vector<int> next(min(B + 1, (int)(curr.size() + child.size() - 1)), 0);
                for (int i = 0; i < curr.size(); ++i)
                    for (int j = 0; j < child.size() && i + j < next.size(); ++j)
                        next[i + j] = max(next[i + j], curr[i] + child[j]);
                curr = next;
            };
            merge(skip, dp[v][0]);
            merge(buy, dp[v][1]);
        }

        int cost = P[u-1], profit = F[u-1], half = cost / 2;
        int sz = min(B + 1, (int)max(skip.size(), buy.size() + cost));
        
        dp[u] = vector<vector<int>>(2, vector<int>(sz, 0));

        for (int b = 0; b < sz; ++b) {
            int s_val = (b < skip.size()) ? skip[b] : -1e9;
            
            // dp[u][0]: Parent not bought. Options: Skip u OR Buy u (Full Price)
            int full_buy = (b >= cost && b - cost < buy.size()) ? buy[b - cost] + profit - cost : -1e9;
            dp[u][0][b] = max(s_val, full_buy);

            // dp[u][1]: Parent bought. Options: Skip u OR Buy u (Half Price)
            int half_buy = (b >= half && b - half < buy.size()) ? buy[b - half] + profit - half : -1e9;
            dp[u][1][b] = max(s_val, half_buy);
        }
    }

    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        adj.assign(n + 1, {});
        for (auto& e : hierarchy) adj[e[0]].push_back(e[1]);
        P = present; F = future; B = budget;
        dp.resize(n + 1);

        dfs(1);
        
        // max profit possible at root within budget
        int ans = 0;
        for (int x : dp[1][0]) ans = max(ans, x);
        return ans;
    }
};