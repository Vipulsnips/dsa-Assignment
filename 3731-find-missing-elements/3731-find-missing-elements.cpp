class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int i=nums[0],n=nums.size(),j=0;
        while(i<=nums[n-1] && j<n){
            if(i==nums[j]){
                i++;
                j++;
                continue;
            }
            while(i<nums[j]){
                ans.push_back(i);
                i++;
            }
            i++;
            j++;
        }
        return ans;
    }
};