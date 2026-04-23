
class Solution {
public:
#define ll long long
    vector<long long> distance(vector<int>& a) {
        ll n=a.size();
        vector <pair<ll,ll>> pre(n);
        map<ll,pair<ll,ll>> mp;
        for(ll i=n-1;i>=0;i--){
            ll val=a[i],freq,sum=i;
            if(! mp.count(val)){
                freq=1;
            }
            else{
                sum+=mp[val].first;
                freq=mp[val].second + 1;
            }
            mp[val]={sum,freq};
            pre[i]={sum,freq};
        }
        vector <long long> ans(n);
        for(ll i=0;i<n;i++){
            ll val=pre[i].first;
            val-= (pre[i].second*i);
            ll rem=mp[a[i]].first-pre[i].first,freq=mp[a[i]].second-pre[i].second;
            val+=( (freq*i) - rem);
            ans[i]=val;
        }
        return ans;
    }
};