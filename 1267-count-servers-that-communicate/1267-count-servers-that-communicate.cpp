class Solution {
public:
    int n,m;
    int dfs(vector<vector<int>>& grid,vector<vector<int>>&visited,int i,int j,int prev){
        int ans=1,flg=0;
        //check row // check column
        for(int ii=0;ii<n;ii++){
            if(grid[ii][j] && !visited[ii][j]){
                visited[ii][j]=1;
                flg=1;ans+=dfs(grid,visited,ii,j,1);
            }
        }
        for(int jj=0;jj<m;jj++){
            if(grid[i][jj] && !visited[i][jj]) {
                visited[i][jj]=1;
                flg=1;ans+=dfs(grid,visited,i,jj,1);
            }
        }
        if(flg || prev) return ans;
        return 0;
    }
    int countServers(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();int ans=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && !visited[i][j]){
                    visited[i][j]=1;
                    ans+=dfs(grid,visited,i,j,0);
                }
            }
        }
        return ans;
    }
};