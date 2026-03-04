class Solution {
public:
    bool check(vector<vector<int>>&a,int i,int j,int n,int m){
        for(int ii=0;ii<n;ii++){
            if(a[ii][j]==1 && ii!=i) return false;
        }
        for(int ii=0;ii<m;ii++){
            if(a[i][ii]==1 && ii!=j) return false;
        }
        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int ans=0,n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    cout<<check(mat,i,j,n,m)<<endl;
                    if(check(mat,i,j,n,m)) ans++;
                }
            }
        }
        return ans;
    }
};