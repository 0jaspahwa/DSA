class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xor_a = 0;

        for(auto &num : nums){ //frist taking xor of all number
            xor_a ^= num;
        }

        long long mask = (xor_a) & (-xor_a); // to get the rightmost set bit
        
        // dividing into grps to get the single single numbers
        int grpa =0; 
        int grpb =0;


        for(auto &i : nums){
            if(i & mask){
                grpa ^= i;
            }
            else{
                grpb ^= i;
            }
        }
        return {grpa,grpb};
    }
};