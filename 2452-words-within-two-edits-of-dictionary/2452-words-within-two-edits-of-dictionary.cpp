class Solution {
public:
    vector<string> twoEditWords(vector<string>& q, vector<string>& d) {
        vector<string> ans;
        int n=q[0].size();
        for(auto i:q){
            int cnt=0;
            for(auto j:d){
                cnt=0;
                for(int k=0;k<n;k++){
                    if(i[k]!=j[k]) cnt++;
                }
                if(cnt<=2){
                    cout<<i<<" "<<j<<endl;
                    ans.push_back(i);
                    break;
                }
            }
            // if(change<=2) ans.push_back(i);
        }
        return ans;
    }
};