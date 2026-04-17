class Solution {
public:
    int minMirrorPairDistance(vector<int>& a) {
        int n=a.size(),ans=INT_MAX;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            int rev=0,temp=a[i];
            while(temp>0){
                rev*=10;
                rev+=(temp%10);
                temp/=10;
            }
            cout<<rev<<endl;
            if(mp.count(a[i])!=0){
                ans=min(ans,i-mp[a[i]]);
            }
            mp[rev]=i;
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};