class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> st;
        int n=s.size();vector<int> a(n,0);
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(i);
            else{
                if(st.size()>1) st.pop();
                else{
                    auto it=st.top();st.pop();
                    a[it]=a[i]=-1;
                }
            }
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(a[i]==-1) continue;
            ans+=s[i];
        }
        return ans;
    }
};