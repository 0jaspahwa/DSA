class Solution {
public:
    int minBitFlips(int start, int goal) {
        int result  = start ^ goal;
        int count =0;
        while(result){
            count += result & 1;
            result >>= 1;
        }
        return count;
    }
};