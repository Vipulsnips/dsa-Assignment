class Solution {
public:
    char findKthBit(int n, int k) {
        string a="0";
        while(a.size()<k){
            int temp=a.size()-1;
            a+='1';
            while(temp>=0){
                if(a[temp]== '1') a+='0';
                else a+='1';
                temp--;
            }
        }
        return a[k-1];
    }
};