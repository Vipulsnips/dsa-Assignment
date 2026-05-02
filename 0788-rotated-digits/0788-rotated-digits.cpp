class Solution {
public:
    int rotatedDigits(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            string t=to_string(i),r="";
            int flg=1;
            for(int j=0;j<t.size();j++){
                if(t[j]=='0' || t[j]=='1' || t[j]=='8') r+=t[j];
                else if (t[j]=='2') r+='5';
                else if(t[j]=='5') r+='2';
                else if (t[j]=='6') r+='9';
                else if(t[j]=='9') r+='6';
                else{
                    flg=0;
                    break;  
                }
            }
            if(flg && t.compare(r)){
                ans++;
            }
        }
        return ans;
    }
};