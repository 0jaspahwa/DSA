class Solution {
public:
    typedef pair<int , pair<int,int>> pp;
    vector<vector<int>> directions = {{0,-1},{0,1},{-1,0},{1,0}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        priority_queue<pp,vector<pp>,greater<>> pq;
        vector<vector<bool>> visited(m , vector<bool>(n,false));

       for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }

        int water =0;

        while(!pq.empty()){
            pp p=pq.top();
            pq.pop();

            int height = p.first;
            int i = p.second.first;
            int j = p.second.second;

            for(vector<int> & dir : directions){
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if(i_>=0 && i_<m && j_ >=0 && j_ < n && !visited[i_][j_]){
                    water += max(height - heightMap[i_][j_], 0);
                    pq.push({max(height,heightMap[i_][j_]),{i_,j_}});
                    visited[i_][j_] = true;
                }
            }
        }
        return water;
    }
};