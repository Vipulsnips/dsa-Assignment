class Solution {
public:
    const int intmin= -6e7;
    string stoneGameIII(vector<int>& a) {
        int n=a.size();
        pair<int,int> dp[n+1][2];
        for(int i=0;i<n+1;i++){
            dp[i][0]={0,0};
            dp[i][1]={0,0};
        }
        for(int i=n-1;i>=0;i--){
           pair<int,int> ans1={intmin,intmin},ans2={intmin,intmin};int val=0;
           for(int k=i;k<n && k<i+3;k++){
                val+=a[k];
                if(val+dp[k+1][1].first > ans1.first){
                    ans1.first=val+dp[k+1][1].first;
                    ans1.second=dp[k+1][1].second;
                }
                if(val+dp[k+1][0].second > ans2.second){
                    ans2.second=val+dp[k+1][0].second;
                    ans2.first=dp[k+1][0].first;
                }
           }
           dp[i][0]=ans1;
           dp[i][1]=ans2;
        }
        if(dp[0][0].first == dp[0][0].second) return "Tie";
        else if(dp[0][0].first<dp[0][0].second) return "Bob";
        else return "Alice";
    }
};