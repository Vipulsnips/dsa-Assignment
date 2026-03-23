class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> dir={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
        int n=grid.size();
        vector <vector<int>> result(n,vector<int> (n,INT_MAX));
        priority_queue<P,vector<P>,greater<P>> pq;
        if(grid[0][0]==1) return -1;
        grid[0][0]=1;
        result[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int dd=pq.top().first,x=pq.top().second.first,y=pq.top().second.second;
            pq.pop();
            for(auto d:dir){
                int x_=x+d[0],y_=y+d[1];
                if(x_>=0 && x_<n && y_>=0 && y_<n && grid[x_][y_]==0 && (dd+1)< result[x_][y_]){
                    result[x_][y_]=dd+1;
                    pq.push({result[x_][y_],{x_,y_}});
                }
            }
        }
        if(result[n-1][n-1]==INT_MAX) return -1;
        else return result[n-1][n-1]+1;
    }
};