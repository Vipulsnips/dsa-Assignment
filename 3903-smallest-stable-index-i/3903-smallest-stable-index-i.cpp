class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int maxm= *max_element(nums.begin(),nums.begin()+i+1);
            int minm= *min_element(nums.begin()+i,nums.end());
            if(maxm-minm <= k) return i;
        }
        return -1;
    }
};