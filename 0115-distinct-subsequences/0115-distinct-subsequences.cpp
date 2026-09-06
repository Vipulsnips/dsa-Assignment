class Solution {
public:
    int dp[1001][1001];
    int solve(string &s ,string &t,int curr,int id){
        if(id==t.size()) return 1;
        if(curr>=s.size()) return 0;
        //pick
        if(dp[curr][id]!=-1) return dp[curr][id];
        int ans=0;
        if(s[curr]==t[id]){
            ans+=solve(s,t,curr+1,id+1);
        }
        // no 
        ans+=solve(s,t,curr+1,id);
        return dp[curr][id]=ans;
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return solve(s,t,0,0);
    }
};