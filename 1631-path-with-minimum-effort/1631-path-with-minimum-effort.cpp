class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({0,{0,0}});
        int ans=0;
        vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}},result(n,vector<int>(m,INT_MAX));
        result[0][0]=0;
        while(!pq.empty()){
            auto curr=pq.top().second;
            pq.pop();
            for(auto d:dir){
                int x=curr.first+d[0];
                int y=curr.second+d[1];
                if(x>=0 && x<n && y>=0 && y<m ){
                    int w=abs(heights[x][y]-heights[curr.first][curr.second]);
                    if(max(w,result[curr.first][curr.second])<result[x][y]){
                        result[x][y]=max(w,result[curr.first][curr.second]);
                        pq.push({result[x][y],{x,y}});
                    }
                }
            }
        }
        return result[n-1][m-1];
    }
};