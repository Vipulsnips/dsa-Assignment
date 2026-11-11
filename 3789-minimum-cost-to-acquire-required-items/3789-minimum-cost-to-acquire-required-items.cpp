class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long minm=min(need1,need2);
        long long op1=cost1+cost2,op2=costBoth;
        long long ans=min(op1*minm,op2*minm);
        need1-=minm;need2-=minm;
        ans+=min(1LL*need1*cost1,1LL*need1*costBoth);
        ans+=min(1LL*need2*cost2,1LL*need2*costBoth);
        return ans;
    }
};