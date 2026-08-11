class Solution {
public:
    int missingInteger(vector<int>& a) {
        int maxm=a[0],cnt=a[0],n=a.size();
        for(int i=1;i<n;i++){
            if(a[i]==a[i-1]+1){
                cnt+=a[i];
                maxm=max(cnt,maxm);
            }
            else{
                break;
            }
        }
        while(1){
            int flg=0;
            for(auto i:a){
                if(i==maxm){
                    flg=1;
                    break;
                }
            }
            if(!flg) return maxm;
            maxm++;
        }
    }
};