class Solution {
public:
    int minOperations(string a) {
        int ans1=0,n=a.size();
        for(int i=0;i<n;i++){
            if(i&1 && a[i]=='0') ans1++;
            else if(!(i&1) && a[i]=='1') ans1++;
        }
        int ans2=0;
        for(int i=0;i<n;i++){
            if(i&1 && a[i]=='1') ans2++;
            else if(!(i&1) && a[i]=='0') ans2++;
        }
        return min(ans1,ans2);
    }

};