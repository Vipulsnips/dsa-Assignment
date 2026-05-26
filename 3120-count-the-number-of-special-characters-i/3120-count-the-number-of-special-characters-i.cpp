class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char,int> m;int ans=0;
        for(char i:word){
            if(i>='a' && i<='z'){
                if(m[i]==0){
                    m[i]++;
                    int x=i-'a';
                    if(m['A'+x]) ans++;
                }
            }
            else{
                if(m[i]==0){
                    m[i]++;
                    int x=i-'A';
                    if(m['a'+x]) ans++;
                }
            }
        }
        return ans;
    }
};