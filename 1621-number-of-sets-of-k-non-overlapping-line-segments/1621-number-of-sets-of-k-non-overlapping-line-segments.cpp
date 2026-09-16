class Solution {
public:
    const int MOD=1e9+7;
    int dp[1001][1001][2];
    int rec(int n,int k,int curr,int flg){
        if(k==0) return 1;
        if(curr==n) return 0;
        if(dp[curr][k][flg]!=-1) return dp[curr][k][flg];
        int ans=0;
        if(!flg){
            //skip or 
            ans=(ans+rec(n,k,curr+1,0))%MOD;
            //take
            ans=(ans+rec(n,k-1,curr+1,0))%MOD;
            //add 
            ans=(ans+rec(n,k,curr+1,1))%MOD;
        }
        if(flg){
            //take
            ans=(ans+rec(n,k-1,curr+1,0))%MOD;
            //add 
            ans=(ans+rec(n,k,curr+1,1))%MOD;
        }
        return dp[curr][k][flg]=ans;
    }
    int numberOfSets(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return rec(n,k,1,0);
    }
};