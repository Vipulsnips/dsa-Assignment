class ProductOfNumbers {
public:
    vector<int> cnt;int sz=0;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num == 0){
            cnt.clear();
            sz=0;
        }
        else if(sz ==0){
            cnt.push_back(num);
            sz++;
        }
        else{
            int x=cnt[sz-1];
            cnt.push_back(num*x);
            sz++;
        }
    }
    
    int getProduct(int k) {
        if(k > sz) return 0;
        int x=cnt[sz-1];
        int rem=sz-k-1;
        if(rem >= 0) x/=cnt[rem];
        return x;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */