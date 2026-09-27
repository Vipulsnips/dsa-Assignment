class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string,string> mp;
        for(auto i:knowledge){
            mp[i[0]]=i[1];
        }
        int n=s.size();string ans;
        for(int i=0;i<n;){
            if(s[i]=='('){
                string curr="";i++;
                while(s[i]!=')') {curr+=s[i];i++;}
                if(mp.count(curr)){
                    ans+=mp[curr];
                }
                else ans+='?';
                i++;
            }
            else{
                ans+=s[i];i++;
            }
        }
        return ans;
    }
};