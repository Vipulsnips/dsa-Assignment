class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(),reservedSeats.end());
        int m=reservedSeats.size(),r=0,c=0,ans=0,change=0;
        for(int i=0;i<m;i++){
            if(reservedSeats[i][0]!=r){
                change++;
                if (r != 0) {
                    if (c == 1)
                        ans += 2;
                    else if (c < 6)
                        ans++;
                }
                r=reservedSeats[i][0];
                if(reservedSeats[i][1]>5) ans++;
                if(reservedSeats[i][1]==10) ans++;
                c=reservedSeats[i][1];
            }
            else{
                int next=reservedSeats[i][1];
                //special case of 2 
                if(c<=1 && next==10) {
                    ans+=2;c=next;continue;
                }
                if(((c<2 && next>5) || (c<4 && next>7) || (c<6 && next>9) )) ans++;
                c= next;
            }
            cout<<reservedSeats[i][0]<<reservedSeats[i][1]<<ans<<endl;
        }
        if (r != 0) {
            if (c == 1)
                ans += 2;
            else if (c < 6)
                ans++;
        }
        return ans+(n-change)*2;
    }
};