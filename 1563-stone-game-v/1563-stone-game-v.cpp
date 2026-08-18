class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> pre(n+1,0);
        pre[1]=stoneValue[0];
        for(int i=1;i<n;i++) pre[i+1]=pre[i]+stoneValue[i];
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                if(j+i>=n) break;
                for(int k=j;k<(j+i);k++){
                    int sum=0,minm=0,l=pre[k+1]-pre[j],r=pre[j+i+1]-pre[k+1];
                    if(l<r){
                        minm=dp[j][k];
                        sum=l;
                        dp[j][j+i]=max(dp[j][j+i],(sum+minm));
                    } else if(l>r){
                        minm=dp[k+1][j+i];
                        sum=r;
                        dp[j][j+i]=max(dp[j][j+i],(sum+minm));
                    }
                    else{
                        dp[j][j+i]=max(dp[j][j+i],(l+dp[j][k]));
                        dp[j][j+i]=max(dp[j][j+i],(r+dp[k+1][j+i]));
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};