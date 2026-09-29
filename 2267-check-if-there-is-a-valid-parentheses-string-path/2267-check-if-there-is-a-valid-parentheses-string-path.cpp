class Solution {
public:
    vector<vector<vector<int>>> dp;
    bool solve(vector<vector<char>>& grid,int i,int j,int val){
        if(j>=grid[0].size() || i>=grid.size()) return false;
        if(grid[i][j]==')') val--;
        else val++;
        if(val<0) return false;
        if(dp[i][j][val]!=-1) return dp[i][j][val];
        bool ans=false;
        //right
        ans|=solve(grid,i+1,j,val);       
        //down
        ans|=solve(grid,i,j+1,val);
        return dp[i][j][val]=ans;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        dp.resize(n,vector<vector<int>>(m, vector<int>((n+m)+1,-1)));
        dp[n-1][m-1][0]=1;
        return solve(grid,0,0,0);
    }
};