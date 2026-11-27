class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        vector<vector<int>> dp(n+1, vector<int>(budget+1, 0));
        vector<int> cnt(n,0);
        int minPrice = INT_MAX;
        for(int i=0;i<n;i++){
            int factor=items[i][0],c=0;
            for(int j=0;j<n;j++){
                if(items[j][0]%factor == 0) c++;
            }
            minPrice = min(minPrice, items[i][1]);
            cnt[i]=c;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=budget;j++){
                dp[i][j]=dp[i+1][j];
                if(items[i][1] <= j ){
                    dp[i][j]=max(dp[i][j], cnt[i]+dp[i+1][j-items[i][1]]);
                }
            }
        }
        int ans = 0;
        for(int j=0;j<=budget;j++){
            ans = max(ans, dp[0][j] + (budget-j)/minPrice);
        }
        return ans;
    }
};