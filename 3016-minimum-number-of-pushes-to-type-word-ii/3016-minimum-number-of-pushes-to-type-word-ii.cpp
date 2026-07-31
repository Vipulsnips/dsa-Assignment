class Solution {
public:
    int minimumPushes(string word) {
        vector<int> c(26,0);
        for(auto i:word) c[i-'a']++;
        sort(c.rbegin(),c.rend());
        int ans=0,curr=1,cnt=1;
        for(auto i:c){
            cout<<i<<endl;
            if(cnt>8){
                cnt=1;
                curr++;
            }
            ans+=i*curr;
            cnt++;
        }
        return ans;
    }
};