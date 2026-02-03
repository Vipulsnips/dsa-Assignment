class Solution {
public:
    bool isTrionic(vector<int>& a) {
        int i=1,n=a.size();
        while(i<n && a[i] > a[i-1]) i++;
        if(i==1 || i==n) return false;
        int j=i;
        while(i<n && a[i]<a[i-1]) i++;
        if(i==j || i==n) return false;
        j=i;
        while(i<n && a[i]>a[i-1]) i++;
        return i==n && j!=i;
    }
};