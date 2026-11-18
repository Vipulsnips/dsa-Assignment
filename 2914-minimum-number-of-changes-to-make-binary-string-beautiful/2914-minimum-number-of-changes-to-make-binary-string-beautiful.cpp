class Solution {
public:
    int minChanges(string s) {
        int ans=0,n=s.size();
        for(int i=1;i<n;i+=2){
            if(s[i-1] != s[i]) ans++;
        }
        return ans;
    }
};