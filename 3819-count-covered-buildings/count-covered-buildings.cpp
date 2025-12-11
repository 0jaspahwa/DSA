class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> maxrow(n+1,0);
        vector<int> minrow(n+1, n+1);
        vector<int> maxcol(n+1,0);
        vector<int> mincol(n+1,n+1);

        for(auto &i : buildings){
            int x = i[0];
            int y = i[1];

            maxrow[y] = max(maxrow[y] , x);
            minrow[y] = min(minrow[y], x);
            maxcol[x] = max(maxcol[x], y);
            mincol[x] = min(mincol[x], y);
        }
        int ans =0;
        for(auto i : buildings){
            int x = i[0];
            int y = i[1];

            if( x < maxrow[y] && x > minrow[y] && y > mincol[x]  && y < maxcol[x]){
                ans+= 1;
            }
        }
        return ans;
    }
};