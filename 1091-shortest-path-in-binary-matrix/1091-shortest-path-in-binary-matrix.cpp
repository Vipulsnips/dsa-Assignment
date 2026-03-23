class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        vector<vector<int>> dir={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
        int n=grid.size();
        int count=0;
        if(grid[0][0]==1) return -1;
        q.push({0,0});grid[0][0]=1;
        while(!q.empty()){
            int N=q.size();
            while(N--){
                auto x=q.front().first,y=q.front().second;
                q.pop();
                if(x==n-1 && y==n-1){
                    return count+1;
                }
                for(auto d:dir){
                    int x_=x+d[0],y_=y+d[1];
                    if(x_>=0 && x_<n && y_>=0 && y_<n && grid[x_][y_]==0){
                        q.push({x_,y_});
                        grid[x_][y_]=1;
                    }  
                }
            }
            count++;
        }
        return -1;
    }
};