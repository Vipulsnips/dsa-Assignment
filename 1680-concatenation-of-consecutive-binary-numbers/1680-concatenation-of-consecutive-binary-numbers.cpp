class Solution {
public:
    const int MOD=1e9+7;
    #define ll long long
    int concatenatedBinary(int n) {
        ll cnt=1,ans=0;
        for(ll i=n;i>=1;i--){
            ll msb=32-__builtin_clz(i);
            for(ll j=0;j<msb;j++){
                if((1LL<<j)&i){
                    ans=(ans+cnt)%MOD;
                }
                cnt=(cnt*2)%MOD;
            }
        }
        return ans;
    }
};