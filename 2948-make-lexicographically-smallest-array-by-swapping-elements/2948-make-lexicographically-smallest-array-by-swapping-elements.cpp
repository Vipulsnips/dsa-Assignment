class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int>a=nums;
        sort(a.begin(),a.end());
        vector<pair<int,int>> vp;
        int n=a.size();
        for(int i=0;i<n;i++) vp.push_back({a[i],i});
        map<int,int> mp;mp[a[0]]=0;
        for(int i=1;i<n;i++){
            mp[a[i]]=i;
            if(vp[i].first-vp[i-1].first <= limit) vp[i].second=vp[i-1].second;
        }
        for(auto &i:nums){
            int curri=mp[i];
            int next=vp[curri].second;
            if(i==8) cout<<curri<<" "<<next<<endl;
            if(next<curri){
                i=a[vp[next].second];
                vp[next].second++;
            }
            else{
                i=a[next];
                vp[curri].second++;
            }
        }
        for(auto i:vp) cout<<i.first<<i.second<<endl;
        return nums;
    }
};