class Solution {
public:
    int mirrorDistance(int n) {
        int temp=n,curr=0;
        while(temp>0){
            curr*=10;
            curr+=(temp%10);
            temp/=10;
        }
        return abs(curr-n);
    }
};