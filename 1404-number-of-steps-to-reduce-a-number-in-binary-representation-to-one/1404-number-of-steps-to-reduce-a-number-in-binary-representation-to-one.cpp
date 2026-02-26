class Solution {
public:
    
    int numSteps(string s) {
        int z=0,flg=0,ans=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='1') flg=1;
            if(s[i]=='0' && flg) z++;
            if(s[i]=='0' && !flg) ans++;
        }
        int o=count(s.begin(),s.end(),'1'),n=s.size();
        // cout<<o<<endl;
        if(z==0 && o==1){
            return count(s.begin(),s.end(),'0');
        }
        ans+=2*z;
        if(o>1) ans++;
        ans+=o;
        cout<<ans<<endl;
        return ans;
    }
};