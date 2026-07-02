class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        deque <vector<int>>q;
        vector<pair<int,int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> ans (n,vector<int>(m,INT_MAX));
        grid[0][0]==0?ans[0][0]=0:ans[0][0]=1;
        q.push_back({0,0,ans[0][0]});
        while(!q.empty()){
            vector<int> curr=q.front();
            int i=curr[0],j=curr[1],val=curr[2];
            // cout<<i<<j<<endl;
            q.pop_front();
            for(auto d:dir){
                int x = i+d.first,y=j+d.second;
                if((x>=0 && x<n) && (y>=0 && y<m)){
                    if(x==n-1 && y==m-1){
                        cout<<i<<j<<x<<y<<val<<endl;
                        if(grid[x][y]==0 && val<health) return true;
                        else if(grid[x][y]==1 && val+1<health)return true;
                        else return false;
                    }
                    if(grid[x][y]==0 && ans[x][y]>val){
                        ans[x][y]=val;
                        q.push_front({x,y,val});
                    }
                    if(grid[x][y]==1 && ans[x][y]>val+1){
                        ans[x][y]=val+1;
                        q.push_back({x,y,val+1});
                    }
                }
            }
        }
        return false;
    }
};