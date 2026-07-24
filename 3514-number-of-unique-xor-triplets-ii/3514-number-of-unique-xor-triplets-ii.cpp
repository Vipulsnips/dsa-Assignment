class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> curr;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                curr.insert(nums[i] ^ nums[j]);
            }
        }
        unordered_set<int> ans;
        for(int i=0;i<n;i++){
            for(auto k:curr){
                ans.insert(nums[i] ^ k);
            }
        }
        return ans.size();
    }
};