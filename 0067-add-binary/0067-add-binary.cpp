class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int c=0,s1=a.size()-1,s2=b.size()-1;
        while(s1>=0 && s2>=0){
            int x=a[s1]-'0',y=b[s2]-'0';
            int sum=x+y+c;
            cout<<sum<<endl;
            if(sum==3){
                ans='1'+ans;
                c=1;
            }
            else if(sum==2){
                ans='0'+ans;
                c=1;
            }
            else if(sum==1){
                ans='1'+ans;
                c=0;
            }
            else if(sum==0){
                ans='0'+ans;
                c=0;
            }
            s1--;
            s2--;
        }
        while(s1>=0){
            int x=a[s1]-'0';
            x+=c;
            if(x==2){
                ans='0'+ans;
                c=1;
            }
            else if(x==1){
                ans='1'+ans;
                c=0;
            }
            else if(x==0){
                ans='0'+ans;
                c=0;
            }
            s1--;
        }
        while(s2>=0){
            int x=b[s2]-'0';
            x+=c;
            if(x==2){
                ans='0'+ans;
                c=1;
            }
            else if(x==1){
                ans='1'+ans;
                c=0;
            }
            else if(x==0){
                ans='0'+ans;
                c=0;
            }
            s2--;
        }
        if(c==1) ans='1'+ans;
        return ans;
    }
};