class Solution {
public:
    bool palindrome(string s, int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    } 
    int maxPalindromes(string s, int k) {
        int ans=0,n=s.size();
        for(int i=0;i<n;){
            if((i+k-1)<n && palindrome(s,i,i+k-1)){
                ans++;
                i=i+k;
            }
            else if((i+k)<n && palindrome(s,i,i+k)){
                ans++;
                i=i+k+1;
            }
            else i++;
        }
        return ans;
    }
};