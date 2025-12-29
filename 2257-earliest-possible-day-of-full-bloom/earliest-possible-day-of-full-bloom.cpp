class Solution {
public:
    int earliestFullBloom(vector<int>& plant, vector<int>& grow) {
        int n = plant.size();
        vector<pair<int,int>> v(n);
        for(int i=0; i<n; i++){
            v[i] = {plant[i],grow[i]};
        }

        auto lambda = [](pair<int,int>& p1,pair<int,int> &p2){
            return p1.second > p2.second;
        };
        sort(v.begin(),v.end(),lambda);

        int maxbloomdays =0;
        int prevplantdays =0;

        for(int i=0; i<n; i++){
            int currplantday = v[i].first;
            int currgrowday = v[i].second;

            prevplantdays += currplantday;
            int currbloomday = prevplantdays + currgrowday;
            maxbloomdays = max(maxbloomdays,currbloomday);
        }
        return maxbloomdays;
    }
};