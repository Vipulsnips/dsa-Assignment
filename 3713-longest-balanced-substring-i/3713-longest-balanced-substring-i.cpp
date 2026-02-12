class Solution {
public:
    int longestBalanced(string s) {
        map<char,int> mp;
        int ans=0;
        for(int i=0;i<s.size();i++){
            mp.clear();
            for(int j=i;j<s.size();j++){
                mp[s[j]]++;
                int curr=-1,cnt=0,flg=1;
                for(auto i:mp){
                    if(curr==-1){
                        curr=i.second;
                        cnt+=i.second;
                    }
                    else{
                        if(curr==i.second) cnt+=i.second;
                        else{
                            flg=0;break;
                        }
                    }
                }
                if(flg) ans=max(ans,cnt);
            }
        }
        return ans;
    }
};