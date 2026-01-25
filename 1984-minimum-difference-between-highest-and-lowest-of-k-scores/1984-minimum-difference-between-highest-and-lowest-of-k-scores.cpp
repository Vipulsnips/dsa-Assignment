class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int curr=0,next=k-1,ans=INT_MAX;
        sort(nums.begin(),nums.end());
        while(next<(nums.size())){
            ans=min(ans,(nums[next]-nums[curr]));
            curr++;
            next++;
        }
        return ans;
    }
};