class Solution {
public:
    vector<int> solveQueries(vector<int>& a, vector<int>& q) {
        int n=a.size();
        vector<int> pre(n),suff(n),ans;
        map<int,int> mp,m;
        for(int i=0;i<n;i++){
            if(!mp.contains(a[i])){
                pre[i]=-1;
            }
            else{
                pre[i]=abs(i-mp[a[i]]);
            }
            mp[a[i]]=i;
        }
        for(int i=n-1;i>=0;i--){
            if(!m.contains(a[i])){
                suff[i]=-1;
            }
            else{
                suff[i]=abs(i-m[a[i]]);
            }
            m[a[i]]=i;
        }
        for(auto i:pre) cout<<i<<" ";
        for(int i=0;i<q.size();i++){
            if(pre[q[i]]==-1 && suff[q[i]]==-1) {ans.push_back(-1);continue;}
            int val1=pre[q[i]];
            if(val1==-1){
                val1=q[i];
                val1+=n-mp[a[q[i]]];
            } 
            int val2=suff[q[i]];
            if(val2 == -1){
                val2=n-1-q[i];
                val2+=m[a[q[i]]]+1;
            }
            ans.push_back(min(val1,val2));
        }
        return ans;
    }
};