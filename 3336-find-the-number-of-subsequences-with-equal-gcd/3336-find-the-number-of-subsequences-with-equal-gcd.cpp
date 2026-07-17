class Solution {
public:
    int dp[201][201][201];
    const int MOD=1e9+7;
    int rec(vector<int>& nums,int f,int s,int i){
        if(i>=nums.size()) return (f == s && f != 0);
        if(dp[f][s][i] != -1) return dp[f][s][i];
        int ans=0;
        ans=(ans+rec(nums,__gcd(f,nums[i]),s,i+1)) % MOD;
        //take in second
        ans=(ans+rec(nums,f,__gcd(s,nums[i]),i+1)) % MOD;
        //skip
        ans=(ans+rec(nums,f,s,i+1)) % MOD;

        return dp[f][s][i]=ans;
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return rec(nums,0,0,0);
    }
};