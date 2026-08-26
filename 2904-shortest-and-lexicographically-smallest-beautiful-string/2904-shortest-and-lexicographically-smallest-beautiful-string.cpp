class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans="";int n=s.size();
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=i;j<n && s[i]=='1';j++){
                if(s[j]=='1') cnt++;
                if(cnt==k){
                    if(ans=="") ans=s.substr(i,j-i+1);
                    else {
                        string curr=s.substr(i,j-i+1);
                        if(curr.size()<ans.size()) ans=curr;
                        else if(curr.size()==ans.size()) ans=min(ans,curr);
                    }
                }
            }
        }
        return ans;
    }
};