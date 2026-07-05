class Solution {
public:
    const int MOD=1e9+7;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();
        vector<vector<pair<int,int>>> dp(n+1,vector<pair<int,int>>(n+1,{0,0}));
        board[n-1][n-1]='0';board[0][0]='0';
        dp[n][n]={0,1};
        vector<pair<int,int>> dir = {{1,0},{1,1},{0,1}};
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(board[i][j]=='X') continue;
                int maxm=-1,cnt=0;
                for(auto d:dir){
                    int x=i+d.first,y=j+d.second;
                    maxm=max(maxm,dp[x][y].first);
                }
                for(auto d:dir){
                    int x=i+d.first,y=j+d.second;
                    if(dp[x][y].first==maxm){
                        cnt=(cnt+dp[x][y].second)%MOD;
                    }
                }
                if(cnt>0)
                dp[i][j]={maxm+int(board[i][j]-'0'),cnt};
            }
        }
        return {dp[0][0].first,dp[0][0].second};
    }
};