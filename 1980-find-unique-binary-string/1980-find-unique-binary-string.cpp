class Solution {
public:
    string solve(set<string>&s,string &a,int i){
        if(i==a.size()){
            if(s.count(a)==0) return a;
            return "";
        }
        string ans="";
        ans=solve(s,a,i+1);
        if(ans!= "" ) return ans;
        a[i]='1';
        ans=solve(s,a,i+1);
        return ans;
    }
    string findDifferentBinaryString(vector<string>& nums) {
    int n = nums.size();
    string ans="";

    for(int i=0;i<n;i++){
        ans += (nums[i][i]=='0' ? '1' : '0');
    }

    return ans;
    }
};