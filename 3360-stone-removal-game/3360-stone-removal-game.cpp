class Solution {
public:
    bool canAliceWin(int n) {
        int i=10,choice=0;
        while(n){
            if(i > n){
                if(!choice) return false;
                else return true;
            }
            n-=i;i--;
            choice^=1;
        }
        if(!choice) return false;
        else return true;
    }
};