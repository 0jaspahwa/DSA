class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xor_a =0;
        for(auto &num : nums){
            xor_a ^= num;
        }
        return xor_a;
    }
};