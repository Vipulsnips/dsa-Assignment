class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int p) {
        vector<int> chote,bade;int cnt=0,n=nums.size();
        for(auto i:nums){
            if(i<p) chote.push_back(i);
            else if(i==p) cnt++;
            else bade.push_back(i);
        }
        while(cnt--) chote.push_back(p);
        for(auto i:bade) chote.push_back(i);
        return chote;
    }
};