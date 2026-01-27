class Solution {
public:
    typedef pair <int,int> p;
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector <p>> adj;
        for(auto edge:edges){
            int u=edge[0],v=edge[1],w=edge[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});
        }
        priority_queue <p , vector <p> ,greater <p> > pq;
        vector <int> result (n,INT_MAX);
        result[0];
        pq.push({0,0}); 
        while(!pq.empty()){
            int d=pq.top().first;
            int curr=pq.top().second;
            pq.pop();
            if(curr == n-1){
                return result[n-1];
            }
            for(auto i:adj[curr]){
                int newd=d+i.second;
                if(newd < result[i.first]){
                    result[i.first]=newd;
                    pq.push({newd,i.first});
                }
            }
        }
        return -1;
    }
};