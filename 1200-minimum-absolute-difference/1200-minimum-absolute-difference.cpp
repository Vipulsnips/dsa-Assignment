class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& a) {
        sort(a.begin(),a.end());
        vector<vector<int>> ans;
        int cnt=INT_MAX;
        for(int i=0;i<a.size() -1;i++){
            cnt=min(a[i+1]-a[i],cnt);
        }
        for(int i=0;i<a.size() -1;i++){
            if(a[i+1]-a[i]==cnt){
                ans.push_back({a[i],a[i+1]});
            }
        }
        return ans;
    }
};