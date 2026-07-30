class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int i=1,ans=0;
        while(n-8>0){
            ans+=(i*8);
            i++;
            n-=8;
        }
        ans += n*i;
        return ans;
    }
};