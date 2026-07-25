class Solution {
public:
    int maxProduct(int n) {
        vector<int> a;
        while(n>0){
            a.push_back(n%10);
            n/=10;
        }
        int maxm=0;
        for(int i=0;i<a.size();i++){
            for(int j=i+1;j<a.size();j++) maxm=max(maxm,a[i]*a[j]);
        }
        return maxm;
    }
};