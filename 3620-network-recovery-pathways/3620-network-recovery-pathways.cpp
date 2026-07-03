class Solution {
public:
    #define ll long long
    bool dijkstra(unordered_map<int,vector<pair<int,int>>> & adj,int mid,long long k,int n){
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        pq.push({0,0});
        vector<int>visited(n+1,0);
        while(!pq.empty()){
            auto [score,curr]= pq.top();
            pq.pop();
            if(visited[curr]) continue;
            visited[curr]=1;
            if(curr==n-1 && score<=k) return true;
            else if(curr==n-1 && score>k) return false;
            for(auto i:adj[curr]){;
                if(!visited[i.first] && i.second>=mid){
                    pq.push({score+i.second,i.first});
                }
            }
        }
        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        int n=online.size();
        int st=0,en=0;
        for(auto i:edges){
            if(online[i[0]] && online[i[1]]){
                adj[i[0]].push_back({i[1],i[2]});
                en=max(en,i[2]);
            }
        }
        while(st<en){
            int mid=(st+en+1)/2;
            if(dijkstra(adj,mid,k,n)){
                st=mid;
            }else{
                en=mid-1;
            }
        }
        if(dijkstra(adj,en,k,n)) return en;
        else if(dijkstra(adj,st,k,n)) return st;
        else return -1;
    }
};

