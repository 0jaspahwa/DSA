class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n =nums.size();
        int result = 0;

        for(int k=0; k<=31; k++){ // checking all 32 bits
            int temp = 1 << k; //check whether the bit is 1 or not
            int counto =0;
            int countz =0;
            for(auto &num : nums){
                if( (num & temp) == 0){ 
                    countz++;
                }
                else{
                    counto++;
                }
            }
            if(counto % 3 == 1){
                result = (result | temp); // setting the bit 1 to get the number
            }
        }
        return result;
        
    }
};