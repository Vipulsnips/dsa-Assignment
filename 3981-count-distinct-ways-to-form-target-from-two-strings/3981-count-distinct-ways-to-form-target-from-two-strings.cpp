class Solution {
public:
    int interleaveCharacters(string a, string b, string target) {
        const int MOD=1e9+7;
        int n=target.size(),m=a.size(),o=b.size();
        int dp[105][105][105]={};
        for(int j=0;j<=m;j++){
            for(int k=0;k<=o;k++){
                dp[n][j][k]=(j>0 && k>0) ?1:0;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m;j>=0;j--){
                for(int k=o;k>=0;k--){
                    long long ans=0;
                    for(int x=j;x<m;x++){
                        if(target[i]==a[x]){
                            ans=(ans+dp[i+1][x+1][k])%MOD;
                        }
                    }
                    for(int x=k;x<o;x++){
                        if(target[i]==b[x]){
                            ans=(ans+dp[i+1][j][x+1])%MOD;
                        }
                    }
                    dp[i][j][k]=ans;
                }
            }
        }
        int remove=0;
        return dp[0][0][0];
    }
};
