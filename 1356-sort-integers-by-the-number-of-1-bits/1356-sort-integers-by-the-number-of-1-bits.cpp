class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int,multiset<int>> mp;
        for(auto i:arr){
            int x= __builtin_popcountll(i);
            mp[x].insert(i);
        }
        vector<int> ans;
        for(auto i:mp){
            for(auto j:i.second) ans.push_back(j);
        }
        return ans;
    }
};