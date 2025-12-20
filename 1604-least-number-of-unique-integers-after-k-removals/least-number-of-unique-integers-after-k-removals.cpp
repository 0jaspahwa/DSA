class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> mp;
        //            type,container,comprator
        priority_queue<int,vector<int>,greater<int>> pq; //min_heap

        for(auto &num : arr){
            mp[num]++;
        }

        for(auto &it :mp){
            pq.push(it.second);
        }

        while( k>0 && !pq.empty()){
            int freq = pq.top();
            if(k >= freq){
                k -= freq;
                pq.pop();
            }
            else{
                k=0;
            }
        }
        return pq.size();

    }
};