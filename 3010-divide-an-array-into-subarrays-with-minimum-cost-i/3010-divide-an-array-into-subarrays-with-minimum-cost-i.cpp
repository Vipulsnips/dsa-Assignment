class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int x=*nums.begin();
        nums.erase(nums.begin());
        sort(nums.begin(),nums.end());
        return *nums.begin() + *(nums.begin()+1)+x;
    }
};