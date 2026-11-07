class Solution {
public:
    typedef long long ll;
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>>avail,notavail;
        for(ll i=0;i<servers.size();i++){
            avail.push({servers[i],i});
        }
        vector<int> ans;ll time=0;
        for(ll i=0;i<tasks.size();i++){
            if(avail.empty()){
                time=(notavail.top())[0];
            }
            while(notavail.size()){
                auto it=notavail.top();
                if(time >= it[0]){
                    avail.push({it[1],it[2]});notavail.pop(); 
                }
                else break;
            }
            auto it=avail.top();
            notavail.push({time+tasks[i],it[0],it[1]});
            ans.push_back(it[1]);
            avail.pop();
            if(time == i) time++;
        }
        return ans;        
    }
};