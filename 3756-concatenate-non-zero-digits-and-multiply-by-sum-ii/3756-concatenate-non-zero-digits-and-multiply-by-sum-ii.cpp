class Solution {
public:
    const int MOD=1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m=s.size();
        vector<long long> pre(m,0),nonzero(m,0),sum(m,0),pow10(m+1);
        pow10[0]=1;
        for(int i=1;i<=m;i++) pow10[i]=(pow10[i-1]*10)%MOD;
        pre[0]=s[0]-'0';nonzero[0]=(pre[0]==0)?0:1;sum[0]=s[0]-'0';
        for(int i=1;i<m;i++){
            if(s[i]=='0') pre[i]=pre[i-1];
            else pre[i]=((pre[i-1]*10)%MOD+(s[i]-'0'))%MOD;
            nonzero[i] = nonzero[i-1] + (s[i] != '0');
            sum[i]+=sum[i-1]+(s[i]-'0');
        }
        vector<int> ans;
        for(auto i:queries){
            long long a=(i[0]==0)?0:pre[i[0]-1],b=pre[i[1]];
            int cnt1=(i[0]==0)?0:nonzero[i[0]-1],cnt2=nonzero[i[1]];
            int x=cnt2-cnt1;
            if(x==0){
                ans.push_back(0);
                continue;
            }
            long long val=(b-(a*pow10[x])%MOD + MOD)%MOD;
            long long add=sum[i[1]]-((i[0]==0)?0:sum[i[0]-1]);
            ans.push_back(((val)%MOD*(add)%MOD)%MOD);
        }
        return ans;
    }
};