class Solution {
public:
    bool checkOnesSegment(string s) {
        int flg=0,ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                flg=1;
            }
            else{
                if(flg) ans++;
                flg=0;
            }
        }
        if(flg) ans++;
        return (ans<=1)?true:false; 
    }
};