class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> comp(n);
        int maxm=nums[0];
        for(int i=0;i<n;i++){
            maxm=max(maxm,nums[i]);
            comp[i]=__gcd(nums[i],maxm);
        }
        sort(comp.begin(),comp.end());
        long long sum=0;
        for(int i=0;i<(n/2);i++){
            sum+=__gcd(comp[i],comp[n-1-i]);
        }
        return sum;
    }
};