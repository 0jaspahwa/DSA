class Solution {
public:
    bool place(int mid, vector<int> &position, int m){
        int first = position[0];
        int ballplaced = 1;

        for(int i=1; i<position.size() && ballplaced < m; i++){
            int curr = position[i];
            if(curr - first >= mid){
                ballplaced += 1;
                first = curr;
            }
        }
        return ballplaced == m;
    }
    int maxDistance(vector<int>& position, int m) {
        int ans = 0;
        int n =position.size();
        sort(position.begin(), position.end());

        int l = 1;
        int r = ceil(position[n-1] / (m-1.0));
 
        while( l<=r){
            int mid = l + (r-l)/2;
            if(place(mid,position,m)){
                ans = mid;
                l= mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
        
    }
};