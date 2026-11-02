class Solution {
public:
    int minMoves2(vector<int>& s) {
        // vector<int> s;map<int,int> mp;
        // for(auto i:nums){
        //     if(mp.count(i)){continue;}
        //     s.push_back(i);mp[i]++;
        // }
        sort(s.begin(),s.end());
        int n=s.size();
        int mid=0;
        if(n&1) mid=s[n/2];
        else mid=(s[n/2]+s[(n/2)-1])/2;
        int ans=0;
        for(auto i:s) ans+=abs(i-mid);
        return ans;
    }
};