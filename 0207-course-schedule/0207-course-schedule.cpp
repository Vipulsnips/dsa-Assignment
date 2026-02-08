class Solution {
public:
    bool solve(unordered_map <int , vector <int > >&adj,int n,vector <int> &indeg){
        int count=0;
        queue <int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
                count++;
            }
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto i:adj[curr]){
                indeg[i]--;
                if(indeg[i]==0){
                    q.push(i);
                    count++;
                }
            }
        }
        return count==n;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map <int , vector <int > > adj;
        vector <int> indeg(numCourses, 0);
        for(auto i : prerequisites){
            adj[i[1]].push_back(i[0]);
            indeg[i[0]]++;
        }

        return solve(adj , numCourses , indeg);
    }
};