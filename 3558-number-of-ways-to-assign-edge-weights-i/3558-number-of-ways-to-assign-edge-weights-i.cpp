class Solution {
public:
    int path=0;
    const long long MOD=1e9+7;
    void dfs(unordered_map<int,vector<int>> &adj,vector<bool>&visited,int curr,int sz){
        visited[curr]=1;
        for(auto i:adj[curr]){
            if(!visited[i]){
                dfs(adj,visited,i,sz+1);
                visited[i]=1;
            }
        }
        path =max(path,sz);
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n =edges.size();
        unordered_map<int,vector<int>> adj;
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool>visited(1e5+5,0); 
        dfs(adj,visited,1,0);
        cout<<path<<endl;
        vector<int> dpe(path,0),dpo(path,0);
        dpe[0]=1;dpo[0]=1;
        for(int i=1;i<path;i++){
            dpo[i]=(dpe[i-1]+dpo[i-1])%MOD;
            dpe[i]=(dpe[i-1]+dpo[i-1])%MOD;
        }
        return dpo[path-1];
    }
};