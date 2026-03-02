class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=0;
        vector<int> cnt(n);
        for(int i=0;i<n;i++){
            int flg=0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==1) break;
                flg++;
            }
            cnt[i]=flg;
        }
        for(auto i:cnt) cout<<i<<endl;
        for(int i=0;i<n-1;i++){
            int wnt=n-1-i,ind =-1;
            for(int j=i;j<n;j++){
                if(cnt[j]>=wnt){
                    ind=j;
                    break;
                }
            }
            if(ind==-1) return -1;
            ans+=(ind-i);
            for(int j=ind;j>=i+1;j--){
                cnt[j]=cnt[j-1];
            }
        }
        return ans;
    }
};