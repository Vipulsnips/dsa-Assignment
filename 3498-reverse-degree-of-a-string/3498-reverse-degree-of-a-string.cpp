class Solution {
public:
    int reverseDegree(string s) {
        int n=s.size(),ans=0;
        for(int i=0;i<n;i++){
            int curr=s[i]-'a';
            ans+=(26-curr)*(i+1);
        }
        return ans;
    }
};