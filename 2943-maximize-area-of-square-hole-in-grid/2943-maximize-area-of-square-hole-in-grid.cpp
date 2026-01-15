class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int h=1,cnt=1,v=1;
        for(int i=1;i<hBars.size();i++){
            if(hBars[i]==1+hBars[i-1]){
                cnt++;
            }
            else{
                cnt=1;
            }
            h=max(h,cnt);
        }
        cnt=1;
        for(int i=1;i<vBars.size();i++){
            if(vBars[i]==1+vBars[i-1]){
                cnt++;
            }
            else{
                cnt=1;
            }
            v=max(v,cnt);
        }
        int minm= min(h+1,v+1);
        return minm*minm;
    }
};