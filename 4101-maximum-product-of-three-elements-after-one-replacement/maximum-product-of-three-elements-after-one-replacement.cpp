class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin()+1, nums.end(),
            [](int x, int y){ return abs(x)>abs(y);});
        return abs(100000LL*nums[0]*nums[1]);
    }
};