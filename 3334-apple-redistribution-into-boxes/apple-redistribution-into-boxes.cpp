class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();
        int count =0;
        int sum=0;
        sort(capacity.begin(),capacity.end(),greater<int>());

        for(int i=0; i<n; i++){
            sum += apple[i];
        }

        for(int j=0; j<m; j++){
            sum -= capacity[j];
            count++;
            if(sum <= 0) break;
        }
        return count;
    }
};