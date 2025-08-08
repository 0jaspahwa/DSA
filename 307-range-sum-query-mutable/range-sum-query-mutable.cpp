class NumArray {
public:
    vector<int> segtree;
    int n;

    void buildtree(vector<int>& nums, int i, int l, int r){
        if(l == r){
            segtree[i] = nums[r];
            return;
        }

        int mid = (l+r)/2;
        buildtree(nums,2*i + 1,l,mid);
        buildtree(nums,2*i + 2,mid+1,r);
        segtree[i] = segtree[2*i + 1] + segtree[2*i + 2];
    }

    int rangesum(int start, int end, int i, int l, int r){
        if(r < start || l > end){
            return 0;
        }

        if(l >= start && r <= end){
            return segtree[i];
        }

        int mid = (l+r)/2;
        int left = rangesum(start,end,2*i+1,l,mid);
        int right = rangesum(start,end,2*i+2,mid+1,r);
        return left+right;
    }

    void updateseg(int idx, int val, int i, int l, int r){
        if(l == r){
            segtree[i] = val;
            return;
        }
        int mid = (l+r)/2;

        if(idx <= mid){
            updateseg(idx,val,2*i+1,l,mid);
        }
        else{
            updateseg(idx,val,2*i + 2,mid+1, r);
        }
        segtree[i] = segtree[2*i + 1] + segtree[2*i + 2];
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segtree.resize(4*n,0);
        buildtree(nums,0,0,n-1);
    }
    
    void update(int index, int val) {
        updateseg(index,val,0,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return rangesum(left,right,0,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */