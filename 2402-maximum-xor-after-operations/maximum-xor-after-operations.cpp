class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int res =0;
        for(auto &i : nums){ // koi bhi number me agar 1bit hai toh result me vahi aayega
            res |= i;
        }
        return res;
    }
};