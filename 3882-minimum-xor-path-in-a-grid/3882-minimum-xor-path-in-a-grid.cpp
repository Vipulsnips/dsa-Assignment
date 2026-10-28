class Solution {
public:
    vector<vector<vector<int>>> dp;
    vector<int>& solve(vector<vector<int>>& grid,int i,int j,int n,int m){
        if(dp[i][j].size()!=0) return dp[i][j];
        dp[i][j].assign(1024,0);
        if(i==n-1 && j==m-1){
            dp[i][j][grid[i][j]]=1;
            return dp[i][j];
        }
        vector<int>s(1024,0);int curr=grid[i][j];
        if(i+1<n){ auto &a = solve(grid,i+1,j,n,m); for(int x=0;x<1024;x++) if(a[x]==1) s[x]=1; }
        if(j+1<m){ auto &b = solve(grid,i,j+1,n,m); for(int x=0;x<1024;x++) if(b[x]==1) s[x]=1; }
        for(int x=0;x<1024;x++){
            if(s[x]==1) dp[i][j][x^curr]=1;
        }
        return dp[i][j];
    }
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        dp.assign(n, vector<vector<int>>(m));
        auto &s=solve(grid,0,0,n,m);
        for(int x=0;x<1024;x++){
            if(s[x]==1) return x;
        }
        return -1;
    }
};