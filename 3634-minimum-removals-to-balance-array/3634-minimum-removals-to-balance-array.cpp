class Solution {
public:
    int minRemoval(vector<int>& a, int k) {
        sort(a.begin(),a.end());
        int ans=INT_MAX,n=a.size();
        for(int i=0;i<n;i++){
            auto it =upper_bound(a.begin(),a.end(),1LL*a[i]*k);
            int d = a.end()-it;
            ans=min(ans, i + d);
        }
        return ans;
    }
};