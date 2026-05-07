class Solution {
public:
    vector<int> maxValue(vector<int>& a) {
        int n=a.size();
        vector<int> pre(n),suff(n);
        pre[0]=a[0];
        for(int i=1;i<n;i++){
            pre[i]=max(a[i],pre[i-1]);
        }
        suff[n-1]=a[n-1];
        for(int i= n-2; i>=0 ;i--){
            suff[i]=min(a[i],suff[i+1]);
        }
        vector<int> ans(n);
        ans[n-1]=pre[n-1];
        for(int i=n-2;i>=0;i--){
            if(pre[i] > suff[i+1]) ans[i]= ans[i+1];
            else ans[i]=pre[i];
        }
        return ans;
    }
};