class Solution {
public:
    int maxRotateFunction(vector<int>& a) {
        int n=a.size();
        int sum=accumulate(a.begin(),a.end(),0),l=n-1,ans=0;
        for(int i=0;i<n;i++){
            ans += (i*a[i]);
        }
        int temp=ans;
        while(l>=0){
            temp+=sum;
            temp-= (a[l] * n);
            ans=max(temp,ans);
            l--;
        }
        return ans;
    }
};