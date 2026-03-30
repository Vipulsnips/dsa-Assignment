class Solution {
public:
    bool checkStrings(string s1, string s2) {
        map<char,int> fe,fo,se,so;
        int n=s1.size();
        for(int i=0;i<n;i++){
            if(i%2==0) {
                fe[s1[i]]++;
                se[s2[i]]++;
            }else{
                fo[s1[i]]++;
                so[s2[i]]++;
            }
        }
        for(auto i:fe){
            if(se[i.first] != i.second) return 0;
        }
        for(auto i:fo){
            if(so[i.first] != i.second) return 0;
        }
        return 1;
    }
};