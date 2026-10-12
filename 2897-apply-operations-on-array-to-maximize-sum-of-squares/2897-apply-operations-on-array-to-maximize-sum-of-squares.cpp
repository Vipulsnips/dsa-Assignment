class Solution {
public:
    const int MOD=1e9+7;
    int maxSum(vector<int>& nums, int k) {
        vector<long long> bits(32,0),a(k,0);int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<32;j++){
                if(nums[i]&(1LL<<j)) bits[j]++;
            }
        }
        for(int i=0;i<32;i++){
            int temp=bits[i],j=0;
            while(j<k && temp--){
                a[j]+=(1LL<<i);
                j++;
            }
        }
        int ans=0;
        for(auto i:a){
            ans=(ans+(1LL*i*i)%MOD)%MOD;
        }
        return ans;
    }
};