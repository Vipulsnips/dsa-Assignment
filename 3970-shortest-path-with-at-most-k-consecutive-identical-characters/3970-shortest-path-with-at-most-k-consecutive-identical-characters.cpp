class Solution {
public:
    typedef pair<int,int> pll;
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        unordered_map<int,vector<pll>> adj;
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
        }
        // dijjstra algo wanna reach n-1, 3 states edge,vertex,count
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,0,1});
        vector<vector<int>> result(n, vector<int>(k + 1, INT_MAX));
        result[0][1]=0;
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            for(auto i:adj[p[1]]){
                int nc = (labels[i.first]==labels[p[1]]) ? p[2]+1 : 1;
                if(nc>k) continue;
                if(result[i.first][nc] > p[0]+i.second){
                    result[i.first][nc]=p[0]+i.second;
                    pq.push({result[i.first][nc],i.first,nc});
                }   
            }
        }
        int ans=INT_MAX;
        for(int c=1;c<=k;c++) ans=min(ans,result[n-1][c]);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};