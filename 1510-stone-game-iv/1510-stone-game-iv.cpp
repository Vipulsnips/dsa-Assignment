class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n+5,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            dp[i]=1;
            for(int j=1;j*j<=i;j++){
                if(dp[i-(j*j)]==1){
                    dp[i]=0;
                    break;
                }
            }
        }
        if(dp[n]==0) return true;
        else return false;
    }
};