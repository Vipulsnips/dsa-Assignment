class Solution {
public:  
    vector<vector<int>>dp;
    bool solve(string &s,string& p,int i,int j){
        //base conditions
        if(j>=p.size() && i>=s.size()){
            return true;
        }
        if(j>=p.size()){
            return i>=s.size();
        }
        if(i>=s.size()) {
            while (j < p.size() && p[j] == '*') j++;
            return j == p.size();
        }

        if(dp[i][j]!=-1) return dp[i][j];
        if(p[j]=='*'){
            return (dp[i][j]=solve(s,p,i,j+1) || solve(s,p,i+1,j));
        }
        else if(p[j]=='?'){
            return dp[i][j]=solve(s,p,i+1,j+1);

        }
        else {
            if(s[i]==p[j]){
                return dp[i][j]=solve(s,p,i+1,j+1);
            }
            else return dp[i][j]= false;
        }
        // return true;
    }
    bool isMatch(string s, string p) {
        dp.resize(s.size(),vector<int>(p.size(),-1));
        return solve(s,p,0,0);
    }
};