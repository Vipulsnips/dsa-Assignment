class Solution {
public:
    bool asteroidsDestroyed(long long mass, vector<int>& a) {
        sort(a.begin(),a.end());
        for(auto i:a){
            if(i>mass) return false;
            else{
                mass+=i;
            }
        }   
        return true;
    }
};