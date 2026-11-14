class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size(),minm=INT_MAX;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(j-i+1 >= l && j-i+1 <=r && sum>0){
                    minm=min(minm,sum);
                }
            }
        }
        if(minm==INT_MAX) return -1;
        return minm;
    }
};