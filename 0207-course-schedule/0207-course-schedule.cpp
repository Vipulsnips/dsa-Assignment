class Solution {
public:
    bool solve(unordered_map <int , vector <int > >&adj,int i,vector <bool> &visited,vector <bool> &inrecursion){
        visited[i]=1;
        inrecursion[i]=1;
        for(auto it:adj[i]){
            if(visited[it] && inrecursion[it]){
                return true;
            }
            if(!visited[it] && solve(adj,it,visited,inrecursion))
                return true;
        }
        inrecursion[i]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map <int , vector <int > > adj;
        for(auto i:prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        vector <bool> visited(numCourses, 0);
        vector <bool> inrecursion(numCourses, 0);
        for(int i=0;i<numCourses;i++){
            if(!visited[i] && solve(adj,i,visited,inrecursion)) return false;
        }
        return true;
    }
};