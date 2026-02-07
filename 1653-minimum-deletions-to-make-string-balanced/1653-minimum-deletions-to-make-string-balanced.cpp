class Solution {
public:
    vector<vector <long long > > dp;
    int solve(string &s , int i , char prev){
        if(i==s.size()) return 0;

        if(prev=='a' && dp[i][0]!=-1) return dp[i][0];
        else if(prev=='b' && dp[i][1]!=-1) return dp[i][1];
        else if(prev=='v' && dp[i][2]!=-1)return dp[i][2];
        
        int ans=INT_MAX;
        if(s[i]=='b'){
            ans=min(ans,solve(s,i+1,'b'));
            ans=min(ans,1+solve(s,i+1,prev));
        }
        if(s[i]=='a'){
            if(prev=='v' || prev=='a'){
                ans=min(ans,solve(s,i+1,'a'));
            }
            ans=min(ans, 1 +solve(s,i+1,prev));
        }
        if(prev=='a') dp[i][0]=ans;
        else if(prev=='b') dp[i][1]=ans;
        else dp[i][2]=ans;
        return ans;
    }
    int minimumDeletions(string s) {
        dp.assign(s.size()+5,vector<long long> (3,-1));
        return solve(s,0,'v');
    }
};