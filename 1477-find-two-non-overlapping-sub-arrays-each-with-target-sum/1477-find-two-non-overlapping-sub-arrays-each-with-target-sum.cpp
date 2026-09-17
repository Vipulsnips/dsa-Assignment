class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int>pre(n,0),ans;
        pre[0]=arr[0];
        for(int i=1;i<n;i++) pre[i]=pre[i-1]+arr[i];
        vector<pair<int,int>> dp(n+1,{n+1,n+1});
        for(int i=n-1;i>=0;i--){
            int prev= (i==0)?0:pre[i-1];
            auto it=lower_bound(pre.begin()+i,pre.end(),prev+target);
            if(it!= pre.end() && *it == (prev+target)){
                int d=distance(pre.begin()+i,it);
                int next1=dp[i+d+1].first,next2=dp[i+d+1].second;
                vector<int>curr={d+1,next1,next2};sort(curr.begin(),curr.end());
                dp[i]={curr[0],curr[1]};
            }
            //skip
            if((dp[i].first==n+1 && dp[i].second==n+1) || (dp[i].first+dp[i].second)>(dp[i+1].first+dp[i+1].second)) dp[i]=dp[i+1];
        }
        if(dp[0].first==n+1 || dp[0].second==n+1) return -1;
        return dp[0].first+dp[0].second;
    }
};