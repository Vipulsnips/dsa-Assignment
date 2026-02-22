class Solution {
public:
    int binaryGap(int n) {
        int msb=32 - __builtin_clz(n);
        int flg=0,cnt=0,ans=0;
        for(int i=0;i<msb;i++){
            if((1<<i)&n){
                if(flg) cnt++;
                flg=1;
                ans=max(cnt,ans);
                cnt=0;
            }
            else{
                if(flg) cnt++;
            }
        }
        return ans;
    }
};