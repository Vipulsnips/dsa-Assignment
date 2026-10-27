class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string curr="";
        for(int i=0;i<n;i++) curr+='.';
        ans.push_back(curr);
        for(int i=1;i<m;i++){
            curr="";
            for(int j=0;j<n-1;j++) curr+='#';
            curr+='.';
            ans.push_back(curr);
        }
        return ans;
    }
};