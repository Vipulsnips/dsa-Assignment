class Solution {
public:
    int minMoves(vector<int>& nums) {
        int i=*max_element(nums.begin(),nums.end());
        int ans=0;
        for(auto j:nums) ans+=i-j;
        return ans;
    }
};