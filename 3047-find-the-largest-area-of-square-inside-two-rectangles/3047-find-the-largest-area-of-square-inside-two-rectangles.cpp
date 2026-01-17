#define ll long long
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n=a.size();
        ll ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ll minx=max(a[i][0],a[j][0]),miny=max(a[i][1],a[j][1]);
                ll maxx=min(b[i][0],b[j][0]),maxy=min(b[i][1],b[j][1]);
                ans=max(ans,min(maxx-minx,maxy-miny));
            }
        }   
        return ans*ans;
    }
};