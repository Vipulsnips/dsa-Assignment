class Solution {
public:
    typedef pair<int,int> p; 
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=healths.size();
        map<int,int> mp;
        priority_queue<p,vector<p>,greater<p>> pq;
        for(int i=0;i<n;i++){
            pq.push({positions[i],i});
            mp[positions[i]]=i;
        }
        vector<int> ans(n,0);
        stack<int> s;
        while(!pq.empty()){
            auto dist=pq.top().first,idx=pq.top().second,val=healths[idx];
            char curr = directions[idx];
            pq.pop();
            if(curr=='R') s.push(idx);
            else{
                int flg=1;
                while(!s.empty()){
                    int ridx=s.top();
                    if(healths[ridx] == 0) continue;
                    s.pop();
                    if(healths[ridx] == val) {
                        flg = 0;
                        healths[ridx] = 0;
                        val = 0;
                        break;
                    }
                    else if(healths[ridx]> val){
                        healths[ridx]--;
                        flg=0;
                        val=0;
                        s.push(ridx);
                        break;
                    }
                    else{
                        val--;
                        healths[ridx]=0;
                    }
                }
                if(flg && val>0) {
                    ans[idx]=val;
                }
                healths[idx] = val;
            }
        }
        while(!s.empty()){
            int curr=s.top();s.pop();
            if(healths[curr]>0) ans[curr]=healths[curr];
        }
        vector<int> res;
        for(int i = 0; i < n; i++){
            if(ans[i] > 0) res.push_back(ans[i]);
        }

        return res;
    }
};