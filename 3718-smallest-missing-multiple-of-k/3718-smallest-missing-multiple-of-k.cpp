class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        map <int,int> mp;
        for(auto i:nums) mp[i]++;
        int tk=k;
        while(mp[tk]!=0){
            tk+=k;
        }
        return tk;
    }
};