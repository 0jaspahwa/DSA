class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>,greater<int>> pq;
        for(auto & num : nums){
            pq.push(num);
        }
        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top());
            pq.pop();
            
        } 
        return result;
    }
    
};