class Solution {
public:
    int ans1=0,ans2=0;
    pair<int,int> solve(vector<int>& nums,int st,int en,int turn){
        if(st>en) return {0,0};
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
            return {f,s};
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        int st=0,en=nums.size()-1;
        pair<int,int> ans =solve(nums,st,en,1);
        cout<<ans.first<<ans.second;
        return ans.first>=ans.second;
    }
};