class Solution {
public:
    int ans1=0,ans2=0;
    pair<int,int> dp[501][501][2];
    pair<int,int> solve(vector<int>& nums,int st,int en,int turn){
        if(st>en) return {0,0};
        if(dp[st][en][turn].first != -1 && dp[st][en][turn].second != -1) return dp[st][en][turn];
        int f=0,s=0;
        if(turn==1){
            pair<int,int> p1=solve(nums,st+1,en,0);
            f=nums[st]+p1.first;
            s=p1.second;
            pair<int,int> p2=solve(nums,st,en-1,0);
            if(nums[en]+p2.first > f){
                f=nums[en]+p2.first;
                s=p2.second;
            }
            return {f,s};
        }
        else{
            pair<int,int> p1=solve(nums,st+1,en,1);
            s=nums[st]+p1.second;
            f=p1.first;
            pair<int,int> p2=solve(nums,st,en-1,1);
            if(nums[en]+p2.second > s){
                f=p2.first;
                s=nums[en]+p2.second;
            }
            return dp[st][en][turn]={f,s};
        }
    }
    bool stoneGame(vector<int>& piles) {
        int st=0,en=piles.size()-1;
        for (int i = 0; i <= 500; i++) {
            for (int j = 0; j <= 500; j++) {
                for(int k=0;k<2;k++) dp[i][j][k] = {-1, -1};
            }
        }
        pair<int,int> ans =solve(piles,st,en,1);
        cout<<ans.first<<ans.second;
        return ans.first>=ans.second;
    }
};