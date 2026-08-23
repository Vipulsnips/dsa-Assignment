class Solution {
public:
    bool sumGame(string num) {
        long long q1=0,q2=0,s1=0,s2=0,n=num.size();
        for(int i=0;i<n;i++){
            if(i<(n/2)){
                if(num[i]=='?') q1++;
                else s1+=int(num[i]-'0');
            }
            else{
                if(num[i]=='?') q2++;
                else s2+=int(num[i]-'0');
            }
        }
        if(q1==q2){
            if(s1==s2) return false;
            else return true;
        }
        if(q1==0){
            long long temp= s2+ ((q2+1)/2)*9;
            if(temp!=s1) return true;
            temp= s2 + ((q2)/2)*9; if(temp!=s1) return true; else return false;
        }
        if(q2==0){
            long long temp= s1+ ((q1+1)/2)*9;
            if(temp!=s2) return true;
            temp= s1 + ((q1)/2)*9; if(temp!=s2) return true; else return false;
        }
        if(q1&1){
            s1+= ((q1)/2+1)*9;
            s2+= ((q2/2))*9;
            if(q2&1) s2+=9;
        }
        else{
            s1+=((q1)/2)*9;
            s2+= ((q2)/2)*9;
        }
        if(s1==s2) return false;
        else return true;
    }
};