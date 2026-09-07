class Solution {
public:
    const int MOD=1e9+7;
    int distinctSubseqII(string s) {
        int n=s.size();long long prev=0;
        vector<long long> c(26,-1);
        for(int i=n-1;i>=0;i--){
            long long temp=prev;
            prev=(prev*2+1)%MOD;
            if(c[s[i]-'a']!=-1){
                prev =(prev-c[s[i]-'a']+MOD) % MOD;
                c[s[i]-'a']=prev;
            }
            c[s[i]-'a']=(temp+1)%MOD;
        }
        return prev;
    }
};