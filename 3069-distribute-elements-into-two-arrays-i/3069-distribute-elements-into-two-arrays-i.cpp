class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> a,b;
        a.push_back(nums[0]);
        b.push_back(nums[1]);
        int i=2;
        while(i<nums.size()){
            if(a[a.size()-1] > b[b.size()-1]){
               a.push_back(nums[i]);
            }
            else{
                b.push_back(nums[i]);
            }
            i++;
        }
        for(auto i:b) a.push_back(i);
        return a;
    }
};