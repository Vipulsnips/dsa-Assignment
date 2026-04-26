class Solution {
public:
    long long minOperations(vector<int>& a) {
        int n=a.size();long long last=a[0];long long sum=0;
        for(int i=1;i<n;i++){
            if((a[i]+sum)<last){
                sum+=last-(a[i]+sum);
            }
            else{
                last=(a[i]+sum);
            }
        }
        return sum;
    }
};