class Solution {
public:
    int n;
    void dfs(vector<int>& parent,string&s,int curr,unordered_map<int,set<int>>&adj,map<char,int>&mp,vector<int> &visited){
        visited[curr]=1;int prev=-1;
        if(mp.count(s[curr])){
            prev=mp[s[curr]];
            adj[parent[curr]].erase(curr);
            adj[prev].insert(curr);
            parent[curr]=prev;
        }
        mp[s[curr]]=curr;
        set<int> children = adj[curr];
        for(auto it:children){
            if(!visited[it]){
                visited[it]=1;
                dfs(parent,s,it,adj,mp,visited);
            }
        }
        //backtrack
        if(prev!=-1) mp[s[curr]]=prev;
        else mp.erase(s[curr]);
    }
    int sizecheck(unordered_map<int,set<int>>&adj,int curr,vector<int>&size,vector<int>&visited){
        int ans=1;
        visited[curr]=1;
        if(adj[curr].size()==0) return size[curr]=ans;
        for(auto it:adj[curr]){
            if(!visited[it]){
                visited[it]=1;
                ans+=sizecheck(adj,it,size,visited);
            }
        }
        return size[curr]=ans;
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        unordered_map<int,set<int>>adj;
        n=parent.size();
        for(int i=1;i<n;i++){
            adj[parent[i]].insert(i);
        }
        map<char,int> mp;vector<int> visited(n,0),size(n,0);
        dfs(parent,s,0,adj,mp,visited);
        visited.assign(n,0);
        sizecheck(adj,0,size,visited);
        return size;
    }
};