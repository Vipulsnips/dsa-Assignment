class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();
        vector<vector<int>> comp(n,vector<int> (26,0));
        set<char> alpha;
        for(int i=n-1;i>=0;i--){
            if(i!=n-1) comp[i]=comp[i+1];
            comp[i][s[i]-'a']++;
            alpha.insert(s[i]);
        }
        int i=-1;string ans="";
        while(i<n){
            set<char> temp=alpha;
            set<pair<char,int>> curr;
            for(auto j:ans) temp.erase(j);
            for(auto j:temp) cout<<j<<endl;
            for(int j=i+1;j<n;j++){
                if(temp.find(s[j]) == temp.end()) continue;
                int flg=1;
                for(auto k:temp){
                    if(!comp[j][k-'a']){
                        flg=0;break;
                    }
                }
                if(flg) curr.insert({s[j],j});
            }
            pair<char,int> front= *curr.begin();
            ans=ans+front.first;
            i=front.second;
            if(ans.size() == alpha.size()) break;
        }
        return ans;
    }

};