class Solution {
public:
    vector<int> starts;
    int t[100001][3]; // [n][count]
    int solve(vector<vector<int>>& events,int i, int count){
        int n = events.size();
        if(count == 2 || i>=n){
            return 0;
        }
        if(t[i][count] != -1){
            return t[i][count];
        }
        int validIdx = upper_bound(starts.begin(),starts.end(),events[i][1]) - starts.begin(); //upper bound iterator deta hai isiliye -starts.begin kiya ki idx ki value mile
        int take = events[i][2] + solve(events,validIdx,count+1);
        int skip = solve(events,i+1,count);
        return t[i][count] = max(take,skip);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());
        for(auto &e : events){
            starts.push_back(e[0]);
        }
        memset(t,-1,sizeof(t));
        return solve(events,0,0);
    }
};