class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<string> s;string ans="";
        for(int i=0;i<arr1.size();i++){
            string t=to_string(arr1[i]);
            for(int j=0;j<(t.size());j++){
                s.insert(t.substr(0,j+1));
            }
        }
        for(int i=0;i<arr2.size();i++){
            string t=to_string(arr2[i]);
            for(int j=0;j<(t.size());j++){
                string temp=t.substr(0,j+1);
                if(s.count(temp) && temp.size()>ans.size()) ans=temp;
            }
        }
        return ans.size();
    }
};