class Solution {
public:
    int n;
    vector<int> dp;
    int solve(vector<int>&a,int i,int d){
        if(dp[i]!=-1) return dp[i];
        int ans=0,t=d;
        for(int j=i+1;j<n && t>0;j++,t--){
            if(a[i]<=a[j]) break;
            else{
                ans=max(ans,solve(a,j,d)+1);
            }
        }
        t=d;
        for(int j=i-1;j>=0 && t>0;j--,t--){
            if(a[i]<=a[j]) break;
            else{
                ans=max(ans,solve(a,j,d)+1);
            }
        }
        return dp[i]=ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        n=arr.size();
        dp.resize(n,-1);
        for(int i=0;i<n;i++){
            solve(arr,i,d);
        }
        return *max_element(dp.begin(),dp.end()) + 1;
    }
};