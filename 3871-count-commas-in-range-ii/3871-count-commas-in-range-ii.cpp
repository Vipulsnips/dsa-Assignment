class Solution {
public:
    typedef long long ll ;
    long long countCommas(long long n) {
        ll ans=0;
        if(n >= 1e3){
            ll t=min(999999LL,n);
            ans+= t-999;
        }
        if(n >= 1e6){
            ll t=min(999999999LL,n);
            ans+= 2*(t-999999);
        }
        if(n >= 1e9){
            ll t=min(999999999999LL,n);
            ans+= 3*(t-999999999);
        }
        if(n >= 1e12){
            ll t=min(999999999999999LL,n);
            ans+= 4*(t-999999999999);
        }
        if(n== 1e15) ans+=5;
        return ans;
    }
};