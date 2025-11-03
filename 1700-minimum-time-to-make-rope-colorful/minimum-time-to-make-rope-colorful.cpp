class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        int n = colors.size();
        int sum =0;

        for(int i=0; i<n-1; i++){
            if(colors[i] == colors[i+1] ){
                sum += min(time[i], time[i+1]);
                time[i+1] = max(time[i],time[i+1]);
            }
        }
        return sum;
    }
};