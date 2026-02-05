class Solution {
public:
    vector <int> ans;
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                int step= nums[i]%n;
                if(step+i < n){
                    ans.push_back(nums[i+step]);
                }
                else{
                    step=abs(n-(step+i));
                    ans.push_back(nums[step]);
                }
            }
            else {
                int step= abs(nums[i])%n;
                if(i-step >=0){
                    ans.push_back(nums[i-step]);
                }
                else{
                    step=abs(n-(abs(i-step)));
                    ans.push_back(nums[step]);
                }
            }
        }
        return ans;
    }
};