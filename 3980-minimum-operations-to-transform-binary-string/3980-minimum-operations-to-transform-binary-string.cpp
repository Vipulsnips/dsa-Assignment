class Solution {
public:
    int minOperations(string s1, string s2) {
        int n=s1.size();
        if(n==1){
            if(s1[0]!=s2[0]){
                if(s1[0]=='1') return -1;
                else return 1;
            }
            else return 0;
        }
        int ans=0,i=0;
        while(i<n){
            if(s1[i]==s2[i]) {
                i++;continue;
            }
            if(s2[i]=='1'){
                ans++;
                i++;
                continue;
            }
            if(i+1<n && s1[i+1]=='1'&& s2[i+1]=='0'){
                ans++;
                i+=2;
            }
            else{
                ans+=2;
                i++;
            }
        }
        return ans;
    }
};