class Solution {
public:
    vector<int> starts;
    int t[100001][3]; // [n][count]

    int binarySearch(vector<vector<int>>& events, int endtime){
        int n = events.size();
        int l=0;
        int r= n-1;
        int result =n;

        while(l <= r){
            int mid = l +(r-l)/2;
            if(events[mid][0] > endtime){
                result = mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return result;
    }
    int solve(vector<vector<int>>& events,int i, int count){
        int n = events.size();
        if(count == 2 || i>=n){
            return 0;
        }
        if(t[i][count] != -1){
            return t[i][count];
        }
        int validIdx = binarySearch(events, events[i][1]); //upper bound iterator deta hai isiliye -starts.begin kiya ki idx ki value mile
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