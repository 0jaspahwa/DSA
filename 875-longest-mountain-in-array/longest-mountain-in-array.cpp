class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if(n<3) return 0;
        
        vector<int> up(n,1);
        vector<int> down(n,1);

        for(int i=1; i<n; i++){
            if(arr[i] > arr[i-1]){
                up[i] = up[i-1] + 1;
            }
        }

        for(int i=n-2; i>=0; i--){
            if(arr[i] > arr[i+1]){
                down[i] = down[i+1] +1;
            }
        }

        int maxlen = 0;

        for(int i=0; i<n; i++){
            if(up[i] > 1 && down[i] > 1){
                int currlen = up[i] + down[i] -1;
                if(currlen >= maxlen){
                    maxlen = currlen;
                }
            }
        }

        return maxlen;


    }
};