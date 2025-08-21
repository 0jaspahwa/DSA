class Solution {
public:
    int oned(vector<int> &vec){
        int cons = 0;
        int subcount=0;

        for(auto &val : vec){
            if(val == 0){
                cons =0;
            }
            else{
                cons++;
            }
            subcount += cons;
        }
        return subcount;

    }
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int result =0;

        for(int startrow=0; startrow<m; startrow++){
            vector<int> vec(n,1);
            for(int endrow=startrow; endrow<m; endrow++){

                for(int col=0; col<n; col++){
                    vec[col] = vec[col] & mat[endrow][col];
                }

                result += oned(vec);
            }
        }
        return result;
    }
};