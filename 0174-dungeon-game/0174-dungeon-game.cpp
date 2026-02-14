class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX));

        // base: imaginary cells outside princess
        dp[n][m-1] = 1;
        dp[n-1][m] = 1;

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int need = min(dp[i+1][j], dp[i][j+1]) - a[i][j];
                dp[i][j] = max(1, need);
            }
        }

        return dp[0][0];
    }
};
