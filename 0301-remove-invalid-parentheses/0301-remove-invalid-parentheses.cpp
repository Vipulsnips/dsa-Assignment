class Solution {
public:
    set<pair<int,string>> ss;
    int min_removals = 1e9;
    void rec(string& s,int i,int r,int curr,string&t){
        if (r > min_removals) return;
        if(i==s.size()){
            if(curr==0 && t.size()!=0) {
                ss.insert({r,t});
                min_removals=min(min_removals,r);
            }
            return;
        }
        if(s[i]!='(' && s[i]!=')') {
            t.push_back(s[i]);
            rec(s,i+1,r,curr,t);    
            t.pop_back();return;
        }
        //take
        if(s[i]=='(') {
            t.push_back(s[i]);
            rec(s,i+1,r,curr+1,t);
            t.pop_back();
        }
        if(s[i]==')' && curr) {
            t.push_back(s[i]);
            rec(s,i+1,r,curr-1,t);
            t.pop_back();
        }
        //no take
        rec(s,i+1,r+1,curr,t);
    }
    vector<string> removeInvalidParentheses(string s) {
        string t = "";
        rec(s,0,0,0,t);
        vector<string> ans;int prev=-1;
        for(auto it=ss.begin();it!=ss.end();it++){
            if(prev==-1) {
                ans.push_back(it->second);
                prev=it->first;
            }
            else{
                if(prev == it->first) ans.push_back(it->second);
                else break;
            }
        }
        if(ans.empty()) return {{}};
        return ans;
    }
};