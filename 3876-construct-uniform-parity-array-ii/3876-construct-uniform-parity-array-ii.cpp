class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int odd=INT_MAX;int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]&1) odd=min(odd,nums[i]);
        }
        // all even
        int flg=1;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0) continue;
            else{
                if(odd==INT_MAX || nums[i]<=odd){
                    flg=0;break;
                }
            }
        }

        if(flg) return true;
        //all odd
        for(int i=0;i<n;i++){
            if(nums[i]&1) continue;
            else{
                if(odd==INT_MAX || nums[i]<=odd){
                    return false;
                }
            }
        }
        return true;
    }
};