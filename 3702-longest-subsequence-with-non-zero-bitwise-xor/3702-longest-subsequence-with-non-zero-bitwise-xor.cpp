class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans=0,cnt=count(nums.begin(),nums.end(),0);
        if(cnt == nums.size()) return 0;
        for(auto i:nums) ans^=i;
        if(ans != 0){
            return nums.size();
        }
        else{
            return nums.size()-1;
        }
    }
};
