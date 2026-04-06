class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set <pair<int,int> > s;
        for(auto i:obstacles){
            s.insert({i[0],i[1]});
        }
        int curr=0,ans=0,x=0,y=0;
        vector <pair<int,int>> vp={{0,1},{1,0},{0,-1},{-1,0}};
        for(auto i:commands){
            if(i==-1){
                curr+=1;
                if(curr>=4) curr=0;
            }
            else if(i==-2){
                curr-=1;
                if(curr<=-1) curr=3;
            }
            else{
                for(int j=1;j<=i;j++){
                    cout<<x<<y<<endl;
                    ans=max(ans,int(pow(x,2)+pow(y,2)));
                    int t1=x+vp[curr].first;
                    int t2=y+vp[curr].second;
                    if(s.find({t1,t2}) != s.end() ) break;
                    x=t1;y=t2;
                }
                ans=max(ans,int(pow(x,2)+pow(y,2)));
            }
        }
        return ans;
    }
};