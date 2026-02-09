class Solution {
public:
    bool BFS(unordered_map <int,vector <int>>&adj,int curr,vector <int>&color,int currColor){
        queue<int> q;
        q.push(curr);
        color[curr]=currColor;
        while(!q.empty()){
            int curr= q.front();
            q.pop();
            for(auto i:adj[curr]){
                if(color[curr]==color[i]) return false;
                if(color[i]==-1){
                    color[i]=1-color[curr];
                    q.push(i);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        unordered_map <int,vector <int> > adj;
        for(int i=0;i<v;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
                adj[graph[i][j]].push_back(i);
            }
        }
        vector <int> color(v,-1);
        for(int i=0;i<v;i++){
            if(color[i]==-1 && !BFS(adj,i,color,1)) return false;
        }
        return true;
    }
};