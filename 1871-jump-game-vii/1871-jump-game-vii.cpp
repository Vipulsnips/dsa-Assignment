class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        vector<int> pre(n+1,0);
        pre[0]=0;
        for(int i=0;i<n;i++){
            if(i!=0) pre[i]=pre[i]+pre[i-1];
            if(i==0 || pre[i] ){
                if(s[i]=='0'){
                    int minm=i+minJump,maxm=i+maxJump;
                    // cout<<i<<" "<<minm<<" "<<maxm<<endl;
                    if(minm<n) pre[minm]++;
                    if(maxm+1<n) pre[maxm+1]--;
                }
            }

        }
        // for(auto i:pre)cout<<i;
        return pre[n-1]>0 && s[n-1]=='0';
    }
};