class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int t=k1+k2;
        int n=nums1.size();
        map<int,long long> mp;int maxm=0;
        for(int i=0;i<n;i++){
            int diff=abs(nums1[i]-nums2[i]);
            maxm=max(diff,maxm);
            mp[diff]++;
        }
        while(maxm > 0){
            if(t>= mp[maxm]){
                t-=mp[maxm];
                mp[maxm-1]+=mp[maxm];
                maxm--;
            }
            else{
                mp[maxm-1]+=t;
                mp[maxm]-=t;
                break;
            }
        }
        long long sum=0;
        for(long long i=maxm;i>=0;i--){
            if(mp.count(i)){
                sum+=(1LL*(i*i)*mp[i]);
            }
        }
        return sum;
    }
};