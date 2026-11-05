class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt=0,n=arr2.size();
        for(auto i:arr1){
            int flg=1;
            for(int j=0;j<n;j++){
                int x= abs(i-arr2[j]);
                if(x<=d){
                    flg=0;
                    break;
                }
            }
            if(flg) cnt++;
        }
        return cnt;
    }
};