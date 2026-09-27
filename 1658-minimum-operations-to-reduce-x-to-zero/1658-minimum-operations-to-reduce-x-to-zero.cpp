class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        vector<int> pre(n),suff(n);
        pre[0]=nums[0];suff[n-1]=nums[n-1];
        for(int i=1;i<n;i++) pre[i]=pre[i-1]+nums[i];
        for(int i=n-2;i>=0;i--) suff[i]=suff[i+1]+nums[i];
        int ans=INT_MAX;
        // pre
        for(int i=0;i<n;i++){
            int curr=pre[i];
            if(pre[i]>x) break;
            if(pre[i]==x){
                ans=min(ans,i+1);
                continue;
            }
            auto it=lower_bound(suff.rbegin(),suff.rbegin()+(suff.size()-i-1),(x-curr));
            if(it!=(suff.rbegin()+(suff.size()-i-1)) && (*it+curr)==x){ 
                ans=min(ans,(i+1)+int(it-suff.rbegin())+1);
            }
        } 
        //suff
        for(int i=n-1;i>=0;i--){
            int curr=suff[i];
            if(suff[i]>x) break;
            if(suff[i]==x){
                ans=min(ans,(n-i));
                continue;
            }
            auto it=lower_bound(pre.begin(),pre.begin()+i,(x-curr));
            if(it!=(pre.begin()+i) && (*it+curr)==x){
                ans=min(ans,(n-i)+int(it-pre.begin())+1);
            }
        } 
        if(ans==INT_MAX) return -1;
        return ans;
    }
};