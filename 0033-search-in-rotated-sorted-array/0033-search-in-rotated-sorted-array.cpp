class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int lo=0,hi=n-1;
        while(lo+1<hi){
            int mid=(lo+hi)/2;
            if(nums[mid] > nums[lo]){
                lo=mid;
            }
            else{
                hi=mid;
            }
        }
        cout<<lo<<hi<<endl;
        if(nums[lo]>nums[hi]){
            auto it = lower_bound(nums.begin(),nums.begin()+lo+1,target);
            if(it!=nums.begin()+lo+1 && *it == target){
                return it-nums.begin();
            }
            it=lower_bound(nums.begin()+lo+1,nums.end(),target);
            // cout<<*it;
            if(it!=nums.end() && *it == target){
                return it-nums.begin();
            }
            else return -1;
        }
        else{
            auto it = lower_bound(nums.begin(),nums.begin()+lo+1,target);
            if(it!=nums.end() && *it == target){
                return it-nums.begin();
            }
            else return -1;
        }
    }
};