class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        //even
        for(int i=0;i<n;i++){
            int flg=0;
            if(nums1[i]%2==0) flg=1;;
            for(int j=0;j<n && !flg;j++){
                if(i==j) continue;
                int x=nums1[i]-nums1[j];
                if(x%2==0){
                    flg=1;
                    break;
                }
            }
            if(!flg) break;
            if(i==n-1) return true;
        }
        //odd
        for(int i=0;i<n;i++){
            int flg=0;
            if(nums1[i]&1) flg=1;
            for(int j=0;j<n && !flg;j++){
                if(i==j) continue;
                int x=nums1[i]-nums1[j];
                cout<<(x&1)<<endl;
                if(x&1){
                    flg=1;
                    break;
                }
            }
            if(!flg) break;
            if(i==n-1) return true;
        }    
        return false;
    }
};