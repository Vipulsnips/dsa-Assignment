class Solution {
public:
    int sumOfPrimesInRange(int n) {
        int t=n,r=0;
        while(t>0){
            r*=10;
            r+=(t%10);
            t/=10;
        }
        cout<<r<<endl;
        int sum=0;
        for(int i=min(n,r);i<=max(n,r);i++){
            if(i==1 || i==0) continue;
            int flg=1;
            for(int j=2;j*j<=i;j++){
                if(i%j==0){
                    flg=0;
                    break;
                }
            }
            if(flg) sum+=i;
        }
        return sum;
    }
};