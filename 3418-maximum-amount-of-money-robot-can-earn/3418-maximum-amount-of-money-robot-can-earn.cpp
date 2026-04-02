class Solution {
public:
    int n, m;
    int dp[505][505][3];
    int rec(vector<vector<int>>&a,int i,int j,int cnt){
        if(i>=n || j>=m) return -INT_MAX;
        if(i==n-1 && j==m-1){
            if(a[i][j]<0 && cnt>0) return dp[i][j][cnt]=0; 
            return dp[i][j][cnt]=a[i][j];
        }
        if(dp[i][j][cnt]!=-INT_MAX) return dp[i][j][cnt];
        //pick
        int ans=-INT_MAX;
        ans=max(ans,a[i][j]+max(rec(a,i+1,j,cnt),rec(a,i,j+1,cnt)));
        //skip
        if(a[i][j]<0){
            if(cnt>0){
                ans=max(ans,max(rec(a,i+1,j,cnt-1),rec(a,i,j+1,cnt-1)));
            }
        }
        return dp[i][j][cnt]=ans;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        n=coins.size(),m=coins[0].size();
        for(int i=0;i<505;i++){
            for(int j=0;j<505;j++){
                for(int k=0;k<3;k++) dp[i][j][k]=-INT_MAX;
            }
        }
        return rec(coins,0,0,2);
    }
};