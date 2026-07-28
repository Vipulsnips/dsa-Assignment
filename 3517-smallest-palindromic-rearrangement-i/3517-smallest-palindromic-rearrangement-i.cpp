class Solution {
public:
    string smallestPalindrome(string s) {
        sort(s.begin(),s.end());
        string ans;int n=s.size();
        if(n&1){
            char mid='Z';int id=-1;
            for(int i=0;i<n;i+=2){
                if(i==n-1 && mid=='Z') {
                    mid=s[i];
                    id=i;
                    break;
                }
                else if(s[i]!=s[i+1]){
                    mid=s[i];
                    id=i;
                    break;
                }
            }
            s.erase(id,1);
            sort(s.begin(),s.end());
            for(int i=0;i<n-1;i+=2){
                ans+=s[i];
            }
            ans+=mid;
            for(int i=n-2;i>=0;i-=2){
                ans+=s[i];
            }
        }
        else{
            for(int i=0;i<n;i+=2){
                ans+=s[i];
            }
            for(int i=n-2;i>=0;i-=2){
                ans+=s[i];
            }
        }
        return ans;
    }
};