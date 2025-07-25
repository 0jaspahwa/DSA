class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int n = N/3;

        vector<long long> leftminsum(N,0);
        vector<long long> rightmaxsum(N,0);

        priority_queue<int> maxheap;
        long long leftsum=0;
        for(int i=0; i<2*n; i++){
            maxheap.push(nums[i]);
            leftsum += nums[i];

            if(maxheap.size() > n){
                leftsum -= maxheap.top();
                maxheap.pop();
            }
            leftminsum[i] = leftsum;
        }

        priority_queue<int, vector<int>, greater<int>> minheap;
        long long rightsum=0;
        for(int i =N-1; i>=n; i--){
            minheap.push(nums[i]);
            rightsum += nums[i];

            if(minheap.size() > n){
                rightsum -= minheap.top();
                minheap.pop();
            }
            rightmaxsum[i] = rightsum;
        }
        long long result = LLONG_MAX;
        for(int i = n-1; i<=2*n-1; i++){
            result = min(result, leftminsum[i] - rightmaxsum[i+1] );
        }
        return result;
    }
};