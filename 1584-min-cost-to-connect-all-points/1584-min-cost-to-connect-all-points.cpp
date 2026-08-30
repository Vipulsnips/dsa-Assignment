class Solution {
public:
    // USING KRUSKAL ALGORITHM
    vector<int> parent;
    vector<int> rank;
    int find (int x) {
        if (x == parent[x]) 
            return x;
    
        return parent[x] = find(parent[x]);
    }
    void Union (int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
    
        if (x_parent == y_parent) 
            return;
    
        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    int Kruskal(vector<vector<int>>&edges){
        auto comparator= [&](vector<int>&a,vector<int>&b){return a[2]<b[2];};
        sort(edges.begin(),edges.end(),comparator);
        int ans=0;
        for(auto i:edges){
            if(find(i[0])!=find(i[1])){
                Union(i[0],i[1]);
                ans+=i[2];
            }
        }
        return ans;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edges;
        int n=points.size();rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            for(int j=i+1;j<n;j++){
                int dist= abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({i,j,dist});
            }
        }
        return Kruskal(edges);
    }
};