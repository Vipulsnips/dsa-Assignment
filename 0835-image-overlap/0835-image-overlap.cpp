class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        set<pair<int,int>> s;
        s.insert({0,0});
        queue<pair<int,int>>q;q.push({0,0});
        vector<pair<int,int>> dir={{-1,0},{1,0},{0,1},{0,-1}};
        int ans=0;
        while(!q.empty()){
            auto it=q.front();q.pop();
            cout<<it.first<<" "<<it.second<<endl;
            int cnt=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(img1[i][j]==0) continue;
                    int x=i+it.first,y=j+it.second;
                    if(x>=0 && x<n && y>=0 && y<n){
                        if(img2[x][y]==1) cnt++;
                    }
                }
            }
            for(auto i:dir){
                int x=i.first+it.first,y=i.second+it.second;
                if(abs(x)<=n && abs(y)<=n && s.find({x,y})==s.end()){
                    s.insert({x,y});
                    q.push({x,y});
                }
            }
            ans=max(cnt,ans);
        }
        return ans;
    }
};