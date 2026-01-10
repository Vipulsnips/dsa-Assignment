class Solution {
public:
    vector <int> pre1,pre2;
    int dp[1005][1005];
    int solve(string &s1,string &s2,int i,int j){
        if (i == s1.size() && j == s2.size()) return 0;
        if(j==s2.size()){
            return pre1[i];
        }
        if(i==s1.size()){
            return pre2[j];
        }
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int curr=0;
        if(s1[i]!=s2[j]){
             curr=int(s2[j]) + solve(s1,s2,i,j+1);
        }
        else{
            curr= solve(s1,s2,i+1,j+1);
        }
        int skip = int(s1[i])+solve(s1,s2,i+1,j);
        return dp[i][j]=min(curr,skip);
    }
    int minimumDeleteSum(string s1, string s2) {
        pre1.resize(s1.size(),0);
        pre1[s1.size()-1]=int(s1[s1.size()-1]);
        for(int i=(s1.size()-2) ; i>=0;i--){
            pre1[i]=pre1[i+1]+int(s1[i]);
        }
        pre2.resize(s2.size(),0);
        pre2[s2.size()-1]=int(s2[s2.size()-1]);
        for(int i=(s2.size()-2) ; i>=0;i--){
            pre2[i]=pre2[i+1]+int(s2[i]);
        }
        for(int i=0;i<1005;i++){
            for(int j=0;j<1005;j++) dp[i][j]=INT_MAX;
        }
        return solve(s1,s2,0,0);
        // cout<<pre[s1.size()-1];
        // return 0;
    }
};