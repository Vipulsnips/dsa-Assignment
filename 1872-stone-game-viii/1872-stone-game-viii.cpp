class Solution {
public:
    int stoneGameVIII(vector<int>& a) {
        int n=a.size();
        vector<int> pre(n,0),dp(n,0);
        pre[0]=a[0];
        for(int i=1;i<n;i++) pre[i]=pre[i-1]+a[i];
        int maxm= pre[n-1];
        for(int i=n-2;i>=0;i--){
            dp[i]=maxm;
            maxm=max(maxm,pre[i]-dp[i]);
        }
        return dp[0];
    }
};