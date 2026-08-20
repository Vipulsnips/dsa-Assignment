class Solution {
public:
    typedef pair<int,int> p;
    int Prims(unordered_map<int,vector<p>>&adj,int n){
        vector<bool> visited(n,0);
        priority_queue<p,vector<p>,greater<p>>q;
        q.push({0,0});int sum=0;
        while(!q.empty()){
            p curr=q.top();
            q.pop();
            if(visited[curr.second]) continue;
            visited[curr.second]=1;
            sum+=curr.first;
            for(auto i:adj[curr.second]){
                if(!visited[i.first]){
                    q.push({i.second,i.first});
                }
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int,vector<p>> adj;
        int n=points.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist= abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj[i].push_back({j,dist});
                adj[j].push_back({i,dist});
            }
        }
        return Prims(adj,n);
    }
};