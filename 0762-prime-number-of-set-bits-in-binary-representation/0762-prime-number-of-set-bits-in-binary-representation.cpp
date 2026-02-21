class Solution {
public:
    bool is_prime(int n){
        if(n==1 || n==0) return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left;i<=right;i++){
            int count=0;
            for(int j=0;j<32;j++){
                if((1<<j)&i) count++;
            }
            cout<<count<<endl;
            if(is_prime(count)) ans++;
        }
        return ans;
    }
};