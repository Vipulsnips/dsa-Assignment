class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        long long n=nums.size(),sleft=0,sright=0;
        multiset<int> left,right;
        vector<long long> pre;
        for(int i=0;i<x;i++){
            left.insert(nums[i]);sleft+=nums[i];
            if(left.size()>(x/2)){
                auto it=left.rbegin();int t=*it;left.erase(next(it).base());
                sleft-=t;sright+=t;
                right.insert(t);
            }
        }
        for(int i=0;i<=n-x;i++){
            long long sum=0,median;
            if(x&1) median=*right.begin();
            else median=(*left.rbegin()+*right.begin())/2;
            sum+=(left.size()*median)-sleft;
            sum+=sright-(right.size()*median);
            pre.push_back(sum);
            //remove
            if(right.find(nums[i])!=right.end())
                {right.erase(right.find(nums[i]));sright-=nums[i];}
            else {left.erase(left.find(nums[i]));sleft-=nums[i];}
            if(i==n-x) break;
            int v=nums[i+x];
            if(right.empty() || v<=*right.begin()){left.insert(v);sleft+=v;}
            else{right.insert(v);sright+=v;};
            if(left.size() > (x/2)){
                auto it=left.rbegin();int t=*it;left.erase(next(it).base());
                sleft-=t;sright+=t;
                right.insert(t);
            }
            if(right.size() > ((x+1)/2)){
                auto it=right.begin();int t=*it;right.erase(it);
                sright-=t;sleft+=t;
                left.insert(t);
            }
        }
        const long long INF=1e18;
        vector<vector<long long>> dp(n+x+2, vector<long long>(k+1, INF));   
        for(int i=n-x;i>=0;i--){
            //take 
            long long take=pre[i];
            //skip
            for(int j=1;j<=k;j++){
                dp[i][j]=dp[i+1][j];
                if(j==1){
                    dp[i][j]=min(dp[i][j],take);
                }
                else if(dp[i+x][j-1]< INF){
                    dp[i][j]=min(dp[i][j],take+dp[i+x][j-1]);
                }
            }
        }
        return dp[0][k];
    }
};