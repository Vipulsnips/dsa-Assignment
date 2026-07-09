class Solution {
public:
    vector<int> parent,rank;
    int find(int m){
        if(m==parent[m]) return m;
        return parent[m]=find(parent[m]);
    }
    void Union(int a,int b){
        int x=find(a),y=find(b);
        if(rank[x]>rank[y]){
            parent[y]=x;
        }
        else if(rank[x]<rank[y]) parent[x]=y;
        else{
            parent[x]=y;
            rank[y]++;
        }
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1] <= maxDiff){
                Union(i,i-1);
            }
        }
        for(int i=0;i<n;i++) {
            parent[i]=find(i);
        }
        vector<bool> ans;
        for(auto q:queries){
            if(parent[q[0]]==parent[q[1]]) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};