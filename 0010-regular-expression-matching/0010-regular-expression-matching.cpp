class Solution {
public:  
    vector <vector <int>> dp;
    bool solve(string &s, string &p,int i,int j){
        if(j==p.size()){
            dp[i][j]=(i==s.size())?1:0;
            return dp[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        bool check = (i < s.size() && (s[i] == p[j] || p[j] == '.'));
        if(j+1<p.size() && p[j+1]=='*'){
            return  dp[i][j]=(check && solve(s,p,i+1,j)||solve(s,p,i,j+2));
        }
        else{
            if(check){
                return dp[i][j]=solve(s,p,i+1,j+1);
            }
            else{
                return dp[i][j]=false;
            }
        }
    }
    bool isMatch(string s, string p) {
        dp.resize(30,vector <int> (30,-1));
        return solve(s,p,0,0);
    }
};