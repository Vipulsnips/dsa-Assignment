class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto i:times){
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<int> result(n+1,INT_MAX);
        result[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            for(auto i:adj[curr.second]){
                if(curr.first+i.second < result[i.first]){
                    result[i.first]=curr.first+i.second;
                    pq.push({result[i.first],i.first});
                }
            } 
        }
        int maxm=0;
        for(int i=1;i<=n;i++) maxm=max(maxm,result[i]);
        return (maxm == INT_MAX)?-1:maxm;
    }
};