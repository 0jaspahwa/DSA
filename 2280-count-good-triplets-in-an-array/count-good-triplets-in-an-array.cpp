class Solution {
public:
    void updatesegtree(int i,int l, int r,int idx,vector<long long>& segtree){
        if(l==r){
            segtree[i] = 1; //mark visited
            return;
        }
        int mid = (l+r) /2;
        if(idx <= mid){
            updatesegtree(2*i+1,l,mid,idx,segtree);
        } else{
            updatesegtree(2*i+2,mid+1,r,idx,segtree);
        }
        segtree[i] = segtree[2*i+1] + segtree[2*i+2];
    }

    long long querysegmenttree(int qs,int qe,int i,int l, int r,vector<long long> &segtree){
        if(r < qs || l > qe){
            return 0;
        }
        if(l>=qs && r<=qe){
            return segtree[i];
        }

        int mid = (r+l) / 2;
        long long left = querysegmenttree(qs,qe,2*i+1,l,mid,segtree);
        long long right = querysegmenttree(qs,qe,2*i+2,mid+1,r,segtree);

        return left + right;
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int, int> mp;
       int n = nums1.size();
       for(int i=0; i<n; i++){
            mp[nums2[i]] = i;
       }

       vector<long long> segtree(4*n);
       long long result =0;

       updatesegtree(0,0,n-1,mp[nums1[0]],segtree);

       for(int i=1; i<n; i++){
            int idx = mp[nums1[i]]; // index in num2

            long long leftcount = querysegmenttree(0,idx-1,0,0,n-1,segtree);
            long long notcommon = i - leftcount;
            long long elementafteridx = (n-1) -idx;
            long long rightcommon = elementafteridx - notcommon;

            result += rightcommon * leftcount;

            updatesegtree(0,0,n-1,idx,segtree);


       }
       return result;

    }
};