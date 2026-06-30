class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=0,b=0,c=0,st=0,en=0,n=s.size(),ans=0;
        while(en<n){
            if(s[en]=='a') a++;
            else if(s[en]=='b') b++;
            else c++;
            while(a && b && c){
                ans+=(n-en);
                if(s[st]=='a') a--;
                else if(s[st]=='b') b--;
                else c--;
                st++;
            }
            en++;
        }
        return ans;
    }
};