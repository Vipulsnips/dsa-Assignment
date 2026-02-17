class Solution {
public:
    vector<int> parent,rank;
    int find(int i){
        if(parent[i]==i) return i;
        return parent[i]=find(parent[i]);
    }
    void Union(int i,int j){
        int x=find(i),y=find(j);
        if(x==y) return;
        if(rank[x]>rank[y]) parent[y]=x;
        else if(rank[x]<rank[y]) parent[x]=y;
        else{
             parent[y]=x;
             rank[x]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < (n-1)) return -1;
        parent.resize(n);
        rank.assign(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
        for(auto i:connections){
            Union(i[0],i[1]);
        }
        set<int> s;
        for(int i=0;i<n;i++){
            find(i);
            s.insert(parent[i]);
        }
        return s.size()-1;
    }
};