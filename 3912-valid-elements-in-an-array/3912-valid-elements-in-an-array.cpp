class Solution {
public:
    vector<int> findValidElements(vector<int>& a) {
        vector<int>ans;int n=a.size();
         ans.push_back(a[0]);
        for(int i=1;i<n-1;i++){
            int flg=0;
            for(int j=0;j<i;j++){
                if(a[j]>=a[i]){
                    flg++;
                    break;
                }
            }
            for(int j=n-1;j>i;j--){
                if(a[j]>=a[i]){
                    flg++;
                    break;
                }
            }
            if(flg==0||flg==1){
                ans.push_back(a[i]);
            }
        }
        if(n>1)
         ans.push_back(a[n-1]);
        return ans;
    }
};