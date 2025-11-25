class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k == 1){
            return 1;
        }
        int nums = 0;
        for(int i=1; i<=k; i++){
            nums = (nums*10+1) % k;

            if(nums == 0){
                return i;
            }
            
        }
    return -1;
    }
};