class Solution {
public:
    int n, m;

    vector<vector<vector<int>>> dir = {
        {},
        {{0,-1},{0,1}},      //1 left right
        {{-1,0},{1,0}},      //2 up down
        {{0,-1},{1,0}},      //3 left down
        {{0,1},{1,0}},       //4 right down
        {{0,-1},{-1,0}},     //5 left up
        {{0,1},{-1,0}}       //6 right up
    };

    bool dfs(int x,int y, vector<vector<int>>& grid, vector<vector<int>>& vis){
        if(x==n-1 && y==m-1) return true;
        vis[x][y]=1;
        for(auto d: dir[grid[x][y]]){
            int nx=x+d[0], ny=y+d[1];
            if(nx<0||ny<0||nx>=n||ny>=m||vis[nx][ny]) continue;
            // check reverse connection
            for(auto back: dir[grid[nx][ny]]){
                if(nx+back[0]==x && ny+back[1]==y){
                    if(dfs(nx,ny,grid,vis)) return true;
                }
            }
        }
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        return dfs(0,0,grid,vis);
    }
};