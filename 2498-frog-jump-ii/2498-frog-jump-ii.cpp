class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n=stones.size();
        if(n==2){
            return stones[1]-stones[0];
        }
        int ans=0;
        for(int i=0;i+2<n;i++){
            ans=max(stones[i+2]-stones[i],ans);
        }
        return ans;
    }
};