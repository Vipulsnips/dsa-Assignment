class Solution {
public:
    int mod=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        vector<int> pre(n,0);
        pre[0]=arr[0]%2;
        for(int i=1;i<n;i++) pre[i]=(pre[i-1]+arr[i])%2;
        long long ans=0;
        vector<pair<long long,long long>> vp(n,{0,0});
        for(int i=n-1;i>=0;i--){
            if(i!=n-1) vp[i]=vp[i+1];
            if(pre[i]&1) vp[i].second++;
            else vp[i].first++;
        }
        int prev=0;
        for(int i=0;i<n;i++){
            if(prev&1) ans=(ans+vp[i].first)%mod;
            else ans=(ans+vp[i].second)%mod;
            prev=pre[i];
        }
        return ans;
    }
};