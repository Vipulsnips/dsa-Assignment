class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int ans=-1,n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            ans=max(ans,(nums[i]+nums[n-1-i]));
        }
        return ans;
    }
};