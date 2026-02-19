class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.size(),cnt=0,ans=0;
        vector<int> a;
        for(int i=0;i<n;i++){
            if((i!=0) && s[i]!=s[i-1]){
                a.push_back(cnt);
                cnt=1;
            }
            else cnt++;
        }
        a.push_back(cnt);
        for(int i=0;i<a.size()-1;i++){
            ans+=min(a[i],a[i+1]);
        }
        return ans;
    }
};