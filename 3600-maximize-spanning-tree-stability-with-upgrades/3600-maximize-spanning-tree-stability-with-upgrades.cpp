class Solution {
public:
    vector<int> rank,parent;
    bool check(int n, vector<vector<int>>& edges,int k,int mid){
        rank.assign(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
        vector<vector<int>> cnt;
        for(auto i:edges){
            if(i[3]==1){
                if(i[2]<mid) return false;
                Union(i[0],i[1]);
            }
            else{
                if(i[2]>=mid){
                    if(find(i[0]) != find(i[1])) Union(i[0],i[1]);
                }else if(2*i[2] >= mid){
                    cnt.push_back(i);
                }
            }
        }
        for(auto &i:cnt){
            if(find(i[0]) != find(i[1])) {
                if(k<=0)  continue;
                Union(i[0],i[1]);
                k--;
            }
        }
        int pp=find(0);
        for(int i=1;i<n;i++){
            if(find(i) != pp) return false;
        }
        return true;
    }
    int find(int i){
        if(parent[i]==i) return i;
        return parent[i]=find(parent[i]);
    }
    void Union(int i,int j){
        int x=find(i),y=find(j);
        if(x==y) return ;
        if(rank[x]>rank[y]) parent[y]=x;
        else if(rank[x]<rank[y]) parent[x]=y;
        else{
            parent[y]=x;
            rank[x]++;
        }
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        rank.assign(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
        for(auto i:edges){
            if(i[3]==1){
                if(find(i[0]) == find(i[1])) return -1;
                Union(i[0],i[1]);
            }
        }
        int lo=1 ,hi=(int)2*1e5,res=-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(check(n,edges,k,mid)){
                res=mid;
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return res;
    }
};