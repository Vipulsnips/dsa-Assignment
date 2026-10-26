class Solution {
public:
    typedef long long ll; 
    ll dfs(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&visited,int n,int m){
        if(grid[i][j]==0) return 0;
        vector<pair<int,int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
        ll ans=grid[i][j];visited[i][j]=1;
        for(auto d:dir){
            int ii=i+d.first,jj=j+d.second;
            if(ii<0 || ii>=n || jj<0 || jj>=m) continue;
            if(visited[ii][jj]==0){
                ans+=dfs(grid,ii,jj,visited,n,m);
            }
        }
        return ans;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        ll ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0){
                    ll sum=dfs(grid,i,j,visited,n,m);
                    if(sum && sum%k==0) ans++;
                }
            }
        }
        return ans; 
    }
};
