class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> digits = {1,2,3,4,5,6,7,8,9},ans;
        for(int i =0;i<9;i++){
            long long curr=0;
            for(int j=i;j<9;j++){
                curr=curr*10 + digits[j];
                if(curr>=low && curr<=high) ans.push_back(curr);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};