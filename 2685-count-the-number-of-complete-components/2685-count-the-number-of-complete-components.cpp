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
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
        unordered_map<int,vector<int>> adj;
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            Union(i[0],i[1]);
        }
        for(int i=0;i<n;i++) parent[i]=find(i);
        map<int,int>mp;
        for(auto i:parent){
            mp[i]++;
        }
        for(int i=0;i<n;i++){
            int val=parent[i];
            if(mp.count(val)!=0 && adj[i].size() != mp[val]-1){
                mp.erase(val);
            }
        }
        return mp.size();
    }
};