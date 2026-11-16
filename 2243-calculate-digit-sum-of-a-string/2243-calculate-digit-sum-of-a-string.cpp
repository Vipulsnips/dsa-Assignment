class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k){
            string t="";
            for(int i=0;i<s.size();i+=k){
                int sum=0;
                for(int j=0;(i+j)<s.size() && j<k;j++){
                    sum+=s[i+j]-'0';
                }
                t+=to_string(sum);
            }
            s=t;
        }
        return s;
    }
};