class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long num=0,sum=0,minm=LLONG_MAX;
        for(auto i:matrix){
            for(auto j:i){
                if(j<0) num++;
                sum+=abs(j);
                minm=min(minm,(long long)(abs(j)));
            }
        }
        if(num&1){
            sum-= (2*minm);
        }
        return sum;
    }
};