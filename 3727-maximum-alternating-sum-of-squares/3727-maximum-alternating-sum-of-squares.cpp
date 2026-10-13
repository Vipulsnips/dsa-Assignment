class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(auto &i:nums) i=abs(i);
        sort(nums.begin(),nums.end());
        int low=0,hi=nums.size()-1;
        long long ans=0;
        while(low<hi){
            ans+=(1LL*nums[hi]*nums[hi]);
            ans-=(1LL*nums[low]*nums[low]);
            hi--;low++;
        }
        if(low==hi)  ans+=(1LL*nums[hi]*nums[hi]);
        return ans;
    }
};