class Solution {
public:
    vector<int> parent,sz;
    int find(int x){
        return (parent[x]==x ? x : parent[x]=find(parent[x]));
    }
    void unite(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b) return;
        if(sz[a]<sz[b]) swap(a,b);
        parent[b]=a;
        sz[a]+=sz[b];
    }
    int minimumHammingDistance(vector<int>& a, vector<int>& b, vector<vector<int>>& c) {
        int n=a.size();
        parent.resize(n);
        sz.resize(n,1);
        iota((parent).begin(), (parent).end(),0);
        for(auto i:c) unite(i[0],i[1]);
        multiset<pair<int,int>> s;
        for(int i=0;i<n;i++) {
            parent[i]=find(i);
            s.insert({parent[i],a[i]});
            // cout<<parent[i]<<" "<<a[i]<<" ";
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int p=parent[i];
            auto it=s.lower_bound({parent[i],b[i]});
            pair<int,int> curr=*it;
            if(it==s.end() || (curr.first!=p || curr.second!=b[i])) continue;
            else {
                s.erase(it);
                ans++;
            }
        }
        return n-ans;
    }
};