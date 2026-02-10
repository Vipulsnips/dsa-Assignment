class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size(),ans=0;
        set <int> even;
        set <int> odd;
        for(int i=0;i<n;i++){
            even.clear();
            odd.clear();
            for(int j=i;j<n;j++){
                if(nums[j]&1) odd.insert(nums[j]);
                else even.insert(nums[j]);
                if(even.size() == odd.size()){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};