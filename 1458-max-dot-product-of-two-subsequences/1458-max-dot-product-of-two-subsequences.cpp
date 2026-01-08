class Solution {
public:
    int dp[505][505];
    int solve(vector<int>& nums1, vector<int>& nums2,int i , int j){
        if(i==nums1.size() || j==nums2.size()){
            return INT_MIN;
        }
        if(dp[i][j]!=INT_MIN) return dp[i][j];
        int ans = INT_MIN;
        int take= nums1[i]*nums2[j];
        int next= solve(nums1,nums2,i+1,j+1);
        if(next>0) take+=next;
        ans=max(ans,take);
        ans=max(ans,solve(nums1,nums2,i+1,j));
        ans=max(ans,solve(nums1,nums2,i,j+1));
        return dp[i][j]=ans;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        for(auto &i:dp){
            for(auto &j:i){
                j=INT_MIN;
            }
        }
        return  solve(nums1,nums2,0,0);
    }
};

