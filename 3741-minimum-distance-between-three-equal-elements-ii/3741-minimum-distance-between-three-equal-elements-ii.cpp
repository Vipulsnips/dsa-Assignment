class Solution {
public:
    int minimumDistance(vector<int>& a) {
        int n=a.size();
        vector<int> cnt(n,-1);
        map<int,int> mp;
        for(int i=n-1;i>=0;i--){
            if(mp[a[i]]==0){
                mp[a[i]]=i;
                continue;
            }
            else{
                cnt[i]=mp[a[i]];
                mp[a[i]]=i;
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(cnt[i]!= -1 && cnt[cnt[i]] != -1){
                int temp=abs(i-cnt[i]) + abs(cnt[i]-cnt[cnt[i]])+abs(cnt[cnt[i]]-i);
                ans=min(ans,temp);
            }
        }
        if(ans!= INT_MAX)
        return ans;
        return -1;
    }
};