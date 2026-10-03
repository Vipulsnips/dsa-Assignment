class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        vector<bool> visited(s.size(), false);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            else {
                if (!st.empty()) {
                    int open = st.top();
                    st.pop();
                    visited[open] = true;
                    visited[i] = true;
                }
            }
        }

        int ans = 0;
        int curr = 0;

        for (bool x : visited) {
            if (x) {
                curr++;
            }
            else {
                ans = max(ans, curr);
                curr = 0;
            }
        }
        ans = max(ans, curr);
        return ans;
    }
};
