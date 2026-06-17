class Solution {
public:
    char processStr(string s, long long k) {
        long long sz=0;
        for(auto i:s){
            if(i=='#') sz+=sz;
            else if(i=='*' && sz) sz--;
            else if(i>='a'&& i<='z') sz++;
        }
        if(k>=sz){
            return '.';
        }
        int i=s.size()-1;
        while(i>=0){
            if(s[i]=='#'){
                sz/=2;
                if(sz<=k) k-=sz;
            }
            else if(s[i]=='*' && sz){
                sz++;
            }
            else if(s[i]=='%'){
                k=sz-k-1;
            }
            else{
                if(k==sz-1){
                    return s[i];
                }
                sz--;
            }
            i--;
        }
        return '.';
    }
};