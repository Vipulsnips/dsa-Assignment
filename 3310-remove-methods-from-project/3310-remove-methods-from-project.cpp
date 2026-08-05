class Solution {
public:
    bool allvalid=false;
    void dfs(vector<vector<int>>&adj,int i,vector<int> & visited,vector<int> & ans,int val){
        if(ans[i]==0 && val) allvalid=true;
        ans[i]=val;
        visited[i]=1;
        for(auto next:adj[i]){
            if(!visited[next]) dfs(adj,next,visited,ans,val);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> visited(n+1,0),ans(n+1,1);
        vector<vector<int>> adj(n+1);
        for(auto i:invocations) adj[i[0]].push_back(i[1]);
        dfs(adj,k,visited,ans,0);
        visited.assign(n+1,0);
        for(int i=0;i<n;i++){
            if(i==k) continue;
            if(!visited[i] && ans[i]) dfs(adj,i,visited,ans,1);
        }
        vector<int> vals;
        if(allvalid) for(int i=0;i<n;i++) vals.push_back(i);
        else for(int i=0;i<n;i++) if(ans[i]==1) vals.push_back(i);
        return vals;
    }
};