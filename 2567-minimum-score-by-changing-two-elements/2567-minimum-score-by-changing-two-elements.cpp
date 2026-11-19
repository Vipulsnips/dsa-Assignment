class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size() <= 3) return 0;
        int n=nums.size(),x=nums[n-1]-nums[2],y=nums[n-3]-nums[0];
        int a = nums[n-1] - nums[2];
        int b = nums[n-2] - nums[1];
        int c = nums[n-3] - nums[0];
        return min({a, b, c});
    }
};