class Solution {
public:
    int maxm,n,m,maxe;
    int bfs(int x,int y,int curr,int en,vector<string>& classroom,vector<vector<int>> & index){
        queue<vector<int>> q;
        q.push({x,y,curr,en,0,0});
        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
        int ans=INT_MAX;
        int bestEnergy[n][m][1<<maxm];memset(bestEnergy,-1,sizeof(bestEnergy));bestEnergy[x][y][0]=en;
        while(!q.empty()){
            vector<int> front=q.front();
            q.pop();
            if(classroom[front[0]][front[1]] == 'L') {
                front[5]|= 1<<index[front[0]][front[1]];
            }
            if(classroom[front[0]][front[1]] == 'R') front[3]=maxe;
            if(front[5]==(1 << maxm)-1) {
                ans=min(ans,front[4]);
                continue;
            }
            if(front[3]==0) continue;
            for(auto d:dir){
                int nx=front[0]+d.first,ny=front[1]+d.second;
                if(nx>=0 && nx<n && ny>=0 && ny<m && classroom[nx][ny]!='X'){
                    if(front[3]-1 > bestEnergy[nx][ny][front[5]]){
                        bestEnergy[nx][ny][front[5]] = front[3] - 1;
                        q.push({nx,ny,front[2],front[3]-1,front[4]+1,front[5]});
                    }
                }
            }
        }
        return ans;
    }
    int minMoves(vector<string>& classroom, int energy) {
        maxm=0,n=classroom.size(),m=classroom[0].size(),maxe=energy;int x,y;
        vector<vector<int>> index(n, vector<int>(m, -1));int cnt=0;
        for(auto i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(classroom[i][j]=='L'){
                    maxm++;
                    index[i][j]=cnt;cnt++;
                }
                if(classroom[i][j]=='S') x=i,y=j;
            }
        }
        int ans=bfs(x,y,0,energy,classroom,index);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};