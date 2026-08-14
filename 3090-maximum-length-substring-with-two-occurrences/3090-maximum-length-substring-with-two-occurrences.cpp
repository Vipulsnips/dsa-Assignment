class Solution {
public:
    int maximumLengthSubstring(string a) {
        int ans=0,st=0,en=0,n=a.size();
        map<char,int> m;
        while(en<n){
            m[a[en]]++;
            if(m[a[en]] >2){
                while(m[a[en]] >2){
                    m[a[st]]--;
                    st++;
                }
            }
            ans=max(ans,en-st+1);
            en++;
        }
        return ans;
    }
};