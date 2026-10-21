class Solution {
public:
    int minOperations(string s) {
        if(is_sorted(s.begin(), s.end())) return 0;
        int n=s.size();
        if(n==2) return -1;
        auto it=*min_element(s.begin(),s.end());
        auto f=find(s.begin(),s.end(),it);
        if(s[0]==it) return 1;
        else if(f==prev(s.end())){
            sort(s.begin()+1,s.end());
            if(is_sorted(s.begin(), s.end())) return 1;
            sort(s.begin(),s.begin()+n-1);
            if(is_sorted(s.begin(), s.end())) return 2;
            return 3;
        }
        else{
            sort(s.begin(),s.begin()+n-1);
            if(is_sorted(s.begin(), s.end())) return 1;
            return 2;
        }
    }
};