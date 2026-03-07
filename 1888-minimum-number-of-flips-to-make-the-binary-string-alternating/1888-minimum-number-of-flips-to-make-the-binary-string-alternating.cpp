class Solution {
public:
    int minFlips(string a) {
        int odd1=0,odd0=0,even1=0,even0=0,n=a.size();
        for(int i=0;i<n;i++){
            if(i&1){
                if(a[i]=='1') odd1++;
                else odd0++;
            }
            else{
                if(a[i]=='1') even1++;
                else even0++;
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int x=min(odd1+even0,even1+odd0);
            ans=min(ans,x);
            if(n%2==0) return ans;
            if(!(i&1)){
                if(a[i]=='1'){
                    even1--;
                    odd1++;
                }
                else{
                    even0--;
                    odd0++;
                }
            }
            else{
                if(a[i]=='1'){
                    odd1--;
                    even1++;
                }
                else{
                    odd0--;
                    even0++;
                }
            }
        }
        return ans;
    }
};