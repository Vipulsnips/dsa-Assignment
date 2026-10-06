class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;int cnt=0;
        for(auto i:s){
            if(i=='(') st.push('(');
            else{
                if(st.empty()) cnt++;
                else st.pop();
            }
        }
        return (cnt+st.size());
    }
};