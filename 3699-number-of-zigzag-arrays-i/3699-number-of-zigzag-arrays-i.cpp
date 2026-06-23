class Solution {
public:
    const int MOD = 1e9+7;
    int zigZagArrays(int n, int l, int r) {
        int dp[n+5][r+5][2];
        for(int i=0;i<=n;i++){
            for(int j=l;j<=r;j++){
                dp[i][j][0] = 0;
                dp[i][j][1] = 0;
            }
        }
        //0--> incr and 1--> decr
        for(int i=1;i<=n;i++){
            //inc
            int x=0;
            for(int j=r;j>=l;j--){
                dp[i][j][0]=(i==1)?1:x;
                x= (x +dp[i-1][j][1]) %MOD;
            }
            //dec
            x=0;
            for(int j=l;j<=r;j++){
                dp[i][j][1]=(i==1)?1:x;
                x = (x + dp[i-1][j][0]) %MOD;
            }
        }
        int cnt=0;
        for(int i=l;i<=r;i++){
            cnt = (cnt + dp[n][i][0]) % MOD ;
            cnt = (cnt + dp[n][i][1]) % MOD;
        }
        return cnt;
    }
};