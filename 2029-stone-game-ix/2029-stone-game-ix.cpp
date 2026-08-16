class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        map<int,int> mp;int n=stones.size();
        for(auto i:stones){
            mp[i%3]++;
        }
        int i=0,cnt1=mp[1],cnt2=mp[2],m=n-mp[0];
        mp[0]%=2;
        // 1 sequence
        for(i;i<m;i++){
            if(i==0 || i==1){
                if(cnt1) cnt1--;
                else break;
                continue;
            }
            if(i%2==0){
                if(cnt2) cnt2--;
                else break;
            }
            else{
                if(cnt1) cnt1--;
                else break;
            }
        }
        if(i!=m  && i!=0){
            if(i&1 && mp[0]==0) return true;
            if(i!=0 && i%2==0 && mp[0]) return true; 
        }
        i=0,cnt1=mp[1],cnt2=mp[2];
        //  2 seq
        for(i;i<m;i++){
            if(i==0 || i==1){
                if(cnt2) cnt2--;
                else break;
                continue;
            }
            if(i%2==0){
                if(cnt1) cnt1--;
                else break;
            }
            else{
                if(cnt2) cnt2--;
                else break;
            }
        }
        if(i!=m && i!=0){
            if(i&1 && mp[0]==0) return true;
            if(i!=0 && i%2==0 && mp[0]) return true; 
        }
        return false;
    }
};