class Solution {
public:
    int minInsertions(string s) {
        int cnt=0,flg=0,ans=0;
        for(auto i:s){
            if(i=='('){
                if(flg){
                    if(!cnt) ans+=2;
                    else{
                        ans++;cnt--;
                    }
                }
                cnt++;
                flg=0;
            }
            else{
                if(flg){
                    if(!cnt) ans++;
                    else cnt--;
                    flg=0;
                }
                else{
                    flg=1;
                }
            }
        }
        cout<<ans<<cnt<<flg<<endl;
        if(cnt){
            ans+=((cnt*2)-flg);
        }
        else if(flg) ans+=2;
        return ans;
    }
};