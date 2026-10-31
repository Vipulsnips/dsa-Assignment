class Solution {
public:
    int n,m,mod=1e9+7;
    int dp[501][501][2];
    int solve(vector<vector<int>>& grid,int i,int j,int dir){
        if(i==n-1 && j==m-1) return 1;
        if(i<0 || i>=n || j<0 || j>=m) return 0;
        if(dp[i][j][dir]!=-1) return dp[i][j][dir];
        int ans=0;
        if(grid[i][j]==1 && !(i==0 && j==0)){
            if(!dir) ans=(ans+solve(grid,i+1,j,1))%mod;
            else ans=(ans+solve(grid,i,j+1,0))%mod;
        }
        else{
            ans=(ans+solve(grid,i+1,j,1))%mod;
            ans=(ans+solve(grid,i,j+1,0))%mod;
        }
        return dp[i][j][dir]=ans;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        //0 means right,1 means down
        memset(dp,-1,sizeof(dp));
        return solve(grid,0,0,0);
    }
};