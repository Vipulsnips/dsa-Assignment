class Solution {
public:
    int maxDistance(vector<int>& a, vector<int>& b) {
        int i=0,j=0,ans=0,n=a.size(),m=b.size();
        while(i<n && j<m){
            while(j+1 < m && b[j+1] >= a[i]) j++;
            if(a[i]<=b[j] && i<=j) ans=max(ans,j-i);
            else j++;
            i++;
        }
        return ans;
    }
};