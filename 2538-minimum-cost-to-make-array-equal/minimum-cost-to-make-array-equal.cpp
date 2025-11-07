class Solution {
public:
    long long findcost(vector<int>& nums, vector<int>& cost, int target){
        int n = nums.size();
        long long value =0;
        for(int i=0; i<n; i++){
            value += 1LL * abs(nums[i] - target) * cost[i];
        }
        return value;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long answer =INT_MAX;
        int n = nums.size();
        int l = *min_element(nums.begin(),nums.end());
        int r = *max_element(nums.begin(),nums.end());

        while(l<=r){
            
            int mid = l + (r-l)/2;
            long long cost1 = findcost(nums,cost,mid);
            long long cost2 = findcost(nums,cost,mid+1);
            answer = min(cost1,cost2);

            if(cost2 > cost1){
                r = mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return answer == INT_MAX ? 0 : answer;
    }
};