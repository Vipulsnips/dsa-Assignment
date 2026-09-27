class Solution {
public:
    vector<array<int,6>> segtree;
    void build_tree(int i,int l,int r,int k,vector<int>&nums){
        if(l==r){
            segtree[i][k]=nums[l]%k;
            segtree[i][nums[l]%k]++;
            return;
        }
        int mid=(l+r)/2;
        build_tree(2*i+1,l,mid,k,nums);
        build_tree(2*i+2,mid+1,r,k,nums);
        array<int,6> left=segtree[2*i+1], right=segtree[2*i+2];
        for(int i=0;i<k;i++) left[(i*left[k])%k]+=right[i];
        left[k]=(left[k]*right[k])%k;
        segtree[i]=left;
    }
    void update(int ind,int val,int i,int l,int r,int k,vector<int> &nums){
        if(l==r){
            segtree[i][nums[l]%k]--;nums[l]=val;
            segtree[i][k]=val%k;
            segtree[i][val%k]++;
            return;
        }
        int mid=(l+r)/2;
        if(ind <= mid ) update(ind,val,2*i+1,l,mid,k,nums);
        else update(ind,val,2*i+2,mid+1,r,k,nums);
        array<int,6> left=segtree[2*i+1], right=segtree[2*i+2];
        for(int i=0;i<k;i++) left[(i*left[k])%k]+=right[i];
        left[k]=(left[k]*right[k])%k;
        segtree[i]=left;
    }
    pair<array<int,5>,int> query(int start,int end,int i,int l,int r,int k){
        if(l>end || r<start){
            array<int,5> d{}; // zero-init
            return {d, 1};    // identity piece: no counts, neutral product
        }
        if(l>=start && r<=end){
            array<int,5> d{};
            for(int j=0;j<k;j++) d[j]=segtree[i][j];
            return {d, segtree[i][k]};
        }
        int mid=(l+r)/2;
        auto left  = query(start,end,2*i+1,l,mid,k);
        auto right = query(start,end,2*i+2,mid+1,r,k);
        array<int,5> merged = left.first;
        for(int j=0;j<k;j++) merged[(j*left.second)%k] += right.first[j];
        int totalProd = (left.second*right.second) % k;
        return {merged, totalProd};
    }
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n=nums.size();
        segtree.resize(4*n, array<int,6>{});n--;
        build_tree(0,0,n,k,nums);
        vector<int> ans;
        for(auto i:queries){
            update(i[0],i[1],0,0,n,k,nums);
            ans.push_back(query(i[2],n,0,0,n,k).first[i[3]]);
        }
        return ans;
    }
};