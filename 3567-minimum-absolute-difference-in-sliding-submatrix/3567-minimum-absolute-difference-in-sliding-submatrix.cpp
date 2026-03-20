class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& a, int k) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1));

        for(int x = 0; x + k <= n; x++){
            for(int y = 0; y + k <= m; y++){
                multiset<int> s;
                for(int i = x; i < x + k; i++){
                    for(int j = y; j < y + k; j++){
                        s.insert(a[i][j]);
                    }
                }
                int minm = INT_MAX;
                int prev = INT_MAX;

                for(auto val : s){
                    if(prev != INT_MAX && prev!=val){
                        minm = min(minm, val - prev);
                    }
                    prev = val;
                }
                if(minm!= INT_MAX)
                ans[x][y] = minm;
                else ans[x][y] = 0;
            }
        }

        return ans;
    }
};