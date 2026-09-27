class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int temp=nums[i],cnt=0;
            while(temp>0){
                cnt+=(temp)%10;
                temp/=10;
            }
            if(cnt==i) return i;
        }
        return -1;
    }
};