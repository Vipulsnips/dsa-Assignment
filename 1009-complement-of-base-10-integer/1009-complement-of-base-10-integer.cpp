class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int ans=0,msb=32 - __builtin_clz(n);
        for(int i=0;i<msb;i++){
            if(!(n&(1<<i))) ans+=(1<<i);
        }
        return ans;
    }
};