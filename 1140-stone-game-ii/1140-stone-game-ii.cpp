class Solution {
public:
    pair<int,int> dp[101][101][2];
    pair<int,int> solve(vector<int>& nums,int i,int m,int turn){
        if(i>=nums.size()) return {0,0};
        if(dp[i][m][turn].first != -1 && dp[i][m][turn].second != -1) return dp[i][m][turn];
        int f=0,s=0;
        if(turn==0){
            int sum=0;
            for(int j=i;j<nums.size() && j<(i+2*m);j++){
                sum+=nums[j];
                pair<int,int> p = solve(nums,j+1,max(m,j-i+1),1);
                if(f < (sum + p.first)){
                    f=sum+p.first;
                    s=p.second;
                }
            }
            return dp[i][m][0]={f,s};
        }
        else{
            int sum=0;
            for(int j=i;j<nums.size() && j<(i+2*m);j++){
                sum+=nums[j];
                pair<int,int> p = solve(nums,j+1,max(m,j-i+1),0);
                if(s < (sum + p.second)){
                    s=sum+p.second;
                    f=p.first;
                }
            }
            return dp[i][m][1]={f,s};
        }
    }
    int stoneGameII(vector<int>& piles) {
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                dp[i][j][1]={-1,-1};
                dp[i][j][0]={-1,-1};
            }
        }
        solve(piles,0,1,0);
        return dp[0][1][0].first;
    }
};
