class Solution {
public:
    bool hasAlternatingBits(int n) {
        int msb=32- __builtin_clz(n);
        cout<<msb<<endl;
        for(int i=0;i<msb;i++){
            if((1<<i)&n && (1<<(i+1))&n) return false;
            if(((1<<i)&n)==0 && (1<<(i+1)&n)==0) return false;
        }
        return true;
    }
};