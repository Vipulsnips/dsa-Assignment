class Solution {
public:
    vector<int> parent,rank;
    int find(int i){
        if(i==parent[i]) return i;
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
    typedef long long ll ;
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.assign(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
        for(auto i:edges){
            if(find(i[0])!=find(i[1])){
                Union(i[0],i[1]);
            }
        }
        map<ll,ll> mp;
        ll ans=0,cnt=n;
        for(int i=0;i<n;i++){
            int x=find(i);
            mp[x]++;
        }
        for(auto i:mp){
            cnt-=i.second;
            ans+=(i.second *cnt);
        }
        return ans;
    }
};