class Solution {
public:
    int bs(int n,vector<pair<int,int>> &arr,int diff){
        int st=0,en=n-1;
        while(st<en){
            int mid = (st+en+1)/2;
            if(arr[mid].first <= diff) st=mid;
            else en=mid-1;
        }
        return st;
    }
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end());
        vector<int> indexConvert(n);
        for(int i=0;i<n;i++){
            indexConvert[arr[i].second] = i;
        }
        int row=n,col=log2(n)+1;
        vector<vector<int>> table(row,vector<int> (col));
        for(int i=0;i<row;i++){
            auto x=bs(n,arr,arr[i].first + maxDiff);
            table[i][0]=x;
        }
        for(int j=1;j<col;j++){
            for(int i=0;i<row;i++){
                table[i][j] = table[table[i][j-1]][j-1];
            }
        }
        vector<int> ans;
        for(auto q:queries){
            int i=q[0],j=q[1];
            if(i==j) {ans.push_back(0);continue;}
            int a=indexConvert[i],b=indexConvert[j];
            if(a>b) swap(a,b);
            int steps=0;
            for(int i=col-1;i>=0;i--){
                if(table[a][i] < b){
                    a=table[a][i];
                    steps+= (1<<i);
                }
            }
            if(table[a][0] >= b) ans.push_back(steps+1);
            else ans.push_back(-1);
        }
        return ans;
    }
};