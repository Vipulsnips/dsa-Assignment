class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> closest(n),ans;
        for(int i=0;i<n;i++){
            if(i==0) closest[i]=1;
            else if(i==n-1) closest[i]=n-2;
            else{
                int left=nums[i]-nums[i-1];
                int right= nums[i+1]- nums[i];
                if(left<=right) closest[i]=i-1;
                else closest[i]=i+1;
            }
        }
        vector<long long> pre(n,0),suf(n,0);
        for(int i=0;i<n-1;i++){
            long long cost;
            if(closest[i]==i+1) cost=1;
            else cost=nums[i+1]-nums[i];
            pre[i+1]= pre[i]+cost;
        }
        for(int i=n-1;i>0;i--){
            long long cost;
            if(closest[i]==i-1) cost=1;
            else cost=nums[i]-nums[i-1];
            suf[i-1]= suf[i]+cost;
        }
        for(auto q:queries){
            int l=q[0],r=q[1];
            if(l<r) ans.push_back(pre[r]-pre[l]);
            else ans.push_back(suf[r]-suf[l]);
        }
        return ans;
    }
};