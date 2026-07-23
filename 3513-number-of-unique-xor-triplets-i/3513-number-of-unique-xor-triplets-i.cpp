class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;
        int x=log2(n),ans=1;
        for(int i=0;i<=x;i++) ans*=2;
        return ans;
    }
};