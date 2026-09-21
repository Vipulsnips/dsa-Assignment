class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        long long n=nums.size();
        vector<vector<long long>> dp(n,vector<long long>(k,0));
        for(long long i=n-1;i>=0;i--){
            if(i==n-1){
                dp[i][nums[i]%k]++;
            }else{
                dp[i][nums[i]%k]++;
                for(long long j=0;j<k;j++){
                    long long curr=dp[i+1][j];
                    long long nj=(j*nums[i])%k;
                    dp[i][nj]+=curr;
                }
            }
        }
        vector<long long>ans(k,0);
        for(auto i:dp){
            for(long long j=0;j<k;j++) ans[j]+=i[j];
        }
        return ans;
    }
};