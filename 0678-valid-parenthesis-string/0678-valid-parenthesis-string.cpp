class Solution {
public:
    int dp[105][105];
    bool solve(string &s,int i,int cnt){
        if(i>=s.size()){
            if(cnt==0) return true;
            return false;
        }
        if(dp[i][cnt]!=-1) return dp[i][cnt];
        bool ans=0;
        if(s[i]=='('){
            return dp[i][cnt]=solve(s,i+1,cnt+1);
        }
        else if(s[i]==')'){
            if(!cnt) return dp[i][cnt]=false;
            return dp[i][cnt]=solve(s,i+1,cnt-1);
        }
        else{
            ans|=solve(s,i+1,cnt);
            ans|=solve(s,i+1,cnt+1);
            if(cnt) ans|=solve(s,i+1,cnt-1);
            return dp[i][cnt]=ans;
        }
    }
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0,0);
    }
};