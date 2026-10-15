class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size(),ans=0;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp.clear();int cnt=0;
            for(int j=i;j<n;j++){
                if(mp[nums[j]]==0){
                    cnt++;
                    mp[nums[j]]=1;
                }
                ans+=(cnt*cnt);
            }
        }
        return ans;
    }
};