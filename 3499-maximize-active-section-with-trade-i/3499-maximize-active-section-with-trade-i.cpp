class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        vector<int> pre(n,0),suf(n,0);
        s[0]=='0'?pre[0]=1:pre[0]=0;s[n-1]=='0'?suf[n-1]=1:suf[n-1]=0;
        int ans=0;
        for(int i=1;i<n;i++) {
            if(s[i]=='0') {
                if(s[i-1]=='1') pre[i]=1;
                else pre[i]=pre[i-1]+1;
            }
            else{
                pre[i]=pre[i-1];
            }
        }
        for(int i=n-2;i>=0;i--){
            if(s[i]=='0') {
                if(s[i+1]=='1') suf[i]=1;
                else suf[i]=suf[i+1]+1;
            }
            else{
                suf[i]=suf[i+1];
            }
        }
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                int j=i;
                while(j<n){
                    if(s[j]=='1') j++;
                    else break;
                }
                j--;
                int sum=0;
                if(pre[i] && suf[j]){
                    sum+=pre[i]+suf[j];
                    cout<<pre[i];
                    ans=max(ans,sum);
                }
                i=j;
            }
        }
        return ans+count(s.begin(),s.end(),'1');
    }
};