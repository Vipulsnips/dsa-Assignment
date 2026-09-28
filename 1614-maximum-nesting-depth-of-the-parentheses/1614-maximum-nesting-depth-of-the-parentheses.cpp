class Solution {
public:
    int maxDepth(string s) {
        int cnt=0,ans=0;
        for(auto i:s){
            if(i=='(') cnt++;
            else if(i==')') cnt--;
            ans=max(ans,cnt);
        }
        return ans;
    }
};