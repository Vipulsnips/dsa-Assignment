class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> cnt(k,0);
        set<int>avail;multiset<vector<int>>notavail;
        int time=arrival[0],n=arrival.size();
        for(int i=0;i<k;i++) avail.insert(i);
        for(int i=0;i<n;i++){
            while(notavail.size()){
                auto it=notavail.begin();
                if((*it)[0]<=time) {avail.insert((*it)[1]);notavail.erase(it);}
                else break;
            }
            if(avail.empty()){
                if(time == arrival[i] && i<(n-1)) time=arrival[i+1];
                continue;
            }
            auto it=avail.lower_bound(i%k);
            if(it==avail.end()){
                it=avail.begin();int x=*it;avail.erase(it);
                cnt[x]++;notavail.insert({time+load[i],x});
            }
            else{
                int x=*it;avail.erase(it);
                cnt[x]++;notavail.insert({time+load[i],x});
            }
            if(time == arrival[i] && i<(n-1)) time=arrival[i+1];
        }
        vector<int> ans;int maxm=*max_element(cnt.begin(),cnt.end());
        for(int i=0;i<k;i++){
            if(cnt[i]==maxm) ans.push_back(i);
        }
        return ans;
    }
};