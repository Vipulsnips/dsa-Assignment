class Solution {
public:
    int minimumPairRemoval(vector<int>& a) {
        int ans=0;
        while(!is_sorted(a.begin(),a.end())){
            int pair=INT_MAX,ind=-1;
            for(int i=0;i<a.size()-1;i++){
                if(a[i]+a[i+1] < pair){
                    pair=a[i]+a[i+1];
                    ind=i;
                }
            }
            a[ind]=pair;
            a.erase(a.begin()+ind+1);
            ans++;
        }
        return ans;
    }
};