class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<vector<int>>a;
        map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int t=nums[i],sum=0;
            while(t>0){
                sum+=t%10;
                t/=10;
            }
            a.push_back({sum,nums[i],i});
        }
        sort(a.begin(),a.end()); 
        int ans=0;
        for(int i=0;i<n;i++){
            mp[i]=a[i][2];
        }
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            int t=i;
            while(!visited[t]){
                visited[t]=1;
                t=mp[t];
            }
            ans++;
        }
        return n-ans;
    }
};