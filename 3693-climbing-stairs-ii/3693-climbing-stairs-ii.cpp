class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<vector<int>> dp(n+1,vector<int>(4,INT_MAX));
        dp[n][1]=dp[n][2]=dp[n][3]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=3;j++){
                if(i+j > n) continue;
                int cost=costs[i+j-1]+(j)*(j),minm=INT_MAX;;
                for(int k=1;k<=3;k++) minm=min(minm,dp[i+j][k]);
                dp[i][j]=min(dp[i][j],cost+minm);
            }
        }
        return min({dp[0][1],dp[0][2],dp[0][3]});
    }
};