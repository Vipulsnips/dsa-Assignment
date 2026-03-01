class Solution {
public:
    int minPartitions(string n) {
        int mx=0;
        for(auto i:n) {
            cout<<i-'0';
            mx=max(mx, i-'0');
        }
        return mx;
    }
};