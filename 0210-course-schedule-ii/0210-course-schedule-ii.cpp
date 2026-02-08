class Solution {
public:
    vector <int> ans;
    bool solve(unordered_map<int, vector<int>>&adj,vector <int> &indeg,int n){
        queue<int> q;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
                ans.push_back(i);
                cnt++;
            }
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto i:adj[curr]){
                indeg[i]--;
                if(indeg[i]==0){
                    q.push(i);
                    ans.push_back(i);
                    cnt++;
                }
            }
        }
        return cnt==n;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector <int> indeg(numCourses,0);
        for(auto i:prerequisites){
            adj[i[1]].push_back(i[0]);
            indeg[i[0]]++;
        }
        if(solve(adj,indeg,numCourses)){
            return ans;
        }
        return {};
    }
};