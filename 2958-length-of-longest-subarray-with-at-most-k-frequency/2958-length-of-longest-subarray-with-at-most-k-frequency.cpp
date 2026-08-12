class Solution {
public:
    int maxSubarrayLength(vector<int>& a, int k) {
        int st=0,en=0,ans=0,n=a.size();
        map<int,int> mp;
        while(en<n){
            mp[a[en]]++;
            if(mp[a[en]] > k){
                while(mp[a[en]] >k){
                    mp[a[st]]--;
                    st++;
                }
            }
            else{
                ans=max(ans,en-st+1);
            }
            en++;
        }
        return ans;
    }
};