class Solution {
public:
    int longestMonotonicSubarray(vector<int>& a) {
        int ans=1,n=a.size();
        for(int i=0;i<n;i++){
            int j=i+1;
            while(j<n){
                if(a[j] > a[j-1]) ans=max(ans,j-i+1);
                else break;
                j++;
            }
            j=i+1;
            while(j<n){
                if(a[j] < a[j-1]) ans=max(ans,j-i+1);
                else break;
                j++;
            }
        }
        return ans;
    }
};