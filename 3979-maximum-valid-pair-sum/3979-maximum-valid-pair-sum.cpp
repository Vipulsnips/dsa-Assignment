class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pre(n,0);
        pre[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            pre[i]=max(pre[i+1],nums[i]);
        }
        int sum=0;
        for(int i=0;i<n;i++){
            if(i+k >=n) break;
            sum=max(sum,(nums[i]+pre[i+k]));
        }
        return sum;
    }
};