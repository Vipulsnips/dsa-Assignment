class Solution {
public:
    bool checkString(string a) {
        int flg=1;
        for(int i=0;i<a.size();i++){
            if(a[i]=='b') flg=0;
            if(a[i]=='a' && !flg) return false;
        }
        return true;
    }
};