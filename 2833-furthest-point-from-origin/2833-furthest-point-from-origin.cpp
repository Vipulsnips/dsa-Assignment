class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n=moves.size(),l=0,r=0;
        for(auto i:moves){
            if(i=='L') l++;
            else if(i=='R') r++;
        }
        return (n-(l+r))+abs(l-r);
    }
};