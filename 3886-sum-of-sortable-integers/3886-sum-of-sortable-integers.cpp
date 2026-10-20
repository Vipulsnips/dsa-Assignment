class Solution {
public:
    int solve(vector<int>& nums,int k){
        int n=nums.size(),last=0;
        for(int i=0;i<n;i+=k){
            //finding drop from subarray
            int ind=i;
            for(int j=i+1;j<i+k;j++){
                if(nums[j-1] > nums[j]){
                    ind=j;
                    break;
                }
            }
            if(last > nums[ind]) return 0;
            last=nums[ind];
            //completing the subarray
            for(int j=ind+1;j<i+k;j++){
                if(last>nums[j]){
                    return 0;
                }
                last=nums[j];
            }
            for(int j=i;j<ind;j++){
                if(last>nums[j]){
                    return 0;
                }
                last=nums[j];
            }
        }
        return k;
    }
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                ans+=solve(nums,i);
            }
            if(n%i==0 && n/i!=i){
                ans+=solve(nums,n/i);
            }
        }
        return ans;
    }
};