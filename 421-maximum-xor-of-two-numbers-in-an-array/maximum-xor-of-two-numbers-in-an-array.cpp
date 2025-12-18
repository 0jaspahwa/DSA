class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max_xor=0;
        int mask =0;

        for(int i=31; i>=0; i--){ // checking from the last bit such that we dont miss out on large number
            mask |= (1 << i); // 
            unordered_set<int> prefix;
            for(int num : nums){
                prefix.insert(num & mask); // har bit ke liye check kr rhe 
            }
            int candidate = max_xor | (1 << i); //greedy ho rhe h next bit me bhi 1 ke liye

            for(auto &i : prefix){ //prefix me har mask ki mapping h
                if(prefix.count(i ^ candidate)){ // A^B = C then A^C = B
                    max_xor = candidate;
                    break;
                }
            }
        }
        return max_xor;

    }
};