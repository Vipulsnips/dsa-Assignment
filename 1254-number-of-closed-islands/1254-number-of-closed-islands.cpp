class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&visited,int n,int m){
        if(grid[i][j]==1) return visited[i][j]=1;
        if(i==0 || i==n-1 || j==0 || j==m-1){
            return visited[i][j]=0;
        }
        vector<pair<int,int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
        int ans=visited[i][j]=1;
        for(auto d:dir){
            int ii=i+d.first,jj=j+d.second;
            if(visited[ii][jj]==-1){
                ans&=dfs(grid,ii,jj,visited,n,m);
            }
            else ans&=visited[ii][jj];
        }
        return visited[i][j]=ans;

    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        //3 states -1,0,1
        vector<vector<int>>visited(n,vector<int>(m,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==-1 && !grid[i][j]){
                    if (dfs(grid,i,j,visited,n,m)) ans++;
                }
            }
        }
        return ans;
    }
};