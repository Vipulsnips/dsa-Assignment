class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int ans=0;
        for(auto i:s){
            if(i=='(') st.push(-1);
            else{
                if(st.top() == -1){
                    st.pop();
                    st.push(1);
                }
                else{
                    int curr=0;
                    while(st.top() != -1){
                        curr+=st.top();st.pop();
                    }
                    st.pop();
                    st.push(2*curr);
                }
            }
        }
        while(!st.empty()){
            ans+=st.top();st.pop();
        }
        return ans;
    }
};