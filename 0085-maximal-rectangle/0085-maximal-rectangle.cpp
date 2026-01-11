class Solution {
private:
        int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        stack<int> st;
        int maxi = 0;
        for(int i=0;i<n;i++){
            int ele = heights[i];
            while(!st.empty() && heights[st.top()] > ele){ 
                int right = i;
                int num_i = st.top();
                st.pop();
                int left = st.empty()?-1:st.top();
                maxi = max(maxi,(right-left-1)*heights[num_i]);
            }
            st.push(i);
        }

        while(!st.empty()){
            int right = n;
            int ele_i = st.top();
            int num = heights[ele_i];
            st.pop();
            int left = st.empty()?-1:st.top();
            maxi = max(maxi,(right-left-1)*num);
        }
        return maxi;
        
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> hist(m,0);
        int maxi = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int ele = matrix[i][j]=='1'?1:0;
                hist[j] = ele==0?0:hist[j]+ele;
            }
            maxi = max(maxi,largestRectangleArea(hist));
        }
        return maxi;
    }
};