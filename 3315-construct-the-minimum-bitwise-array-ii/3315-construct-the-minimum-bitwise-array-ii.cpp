class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(auto i:nums){
            if(i==2) ans.push_back(-1);
            else{
            int curr=0,flg=1;
            for(int j=0;j<=31;j++){
                if(1<<j & i){
                    if(1<<(j+1) & i ) curr+=1<<j;
                    else if(!(1<<(j+1) & i)) {
                        if(flg) flg=0;
                        else curr+=1<<j;
                    }
                }
            }
            ans.push_back(curr);
            }
        }
        return ans;
    }
};