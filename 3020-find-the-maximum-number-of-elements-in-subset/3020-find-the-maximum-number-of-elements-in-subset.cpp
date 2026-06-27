class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = 1e9;
        unordered_map<int,long long> mp;
        for(auto i:nums) mp[i]++;
        vector<bool> visited(1e5+5,false);
        long long ans=1;
        ans = max(ans ,(mp[1]&1)? mp[1]:mp[1]-1 );
        for(int i=2;i*i<=n;i++){
            if(visited[i]) continue;
            if(!mp.count(i)) continue;
            long long x=i,cnt=0;
            visited[x]=true;
            while(mp.count(x)){
                if(x<(1e5+5)) visited[x]=true;
                else if(x<= (1e9)){
                    cnt++;
                    break;
                }
                else break;
                if(mp[x]>=2 && mp.count(x*x)){
                    cnt+=2;
                }
                else {
                    cnt++;
                    break;
                }
                x*=x;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};