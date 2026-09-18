class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<pair<int,int>> c(26,{INT_MAX,INT_MIN});
        int n=s.size();
        for(int i=0;i<n;i++){
            c[s[i]-'a'].first=min(c[s[i]-'a'].first,i);
            c[s[i]-'a'].second=max(c[s[i]-'a'].second,i);
        }
        unordered_map<char,vector<char>> adj;
        for(int i=0;i<26;i++){
            for(int j=c[i].first;j<=c[i].second;j++){
                if(s[j]!=char('a'+i)) adj['a'+i].push_back(s[j]);
            }
        }
        // making subarray
        set<pair<long long,long long>> st; //first val is size of subarray and 2nd is the first index of starting
        for(int i=0;i<26;i++){
            if(c[i].first == INT_MAX) continue;
            //bfs
            int minm=INT_MAX,maxm=INT_MIN;
            queue<char>q;q.push(char('a'+i));
            vector<int> visited(26,0);visited[i]=1;
            while(!q.empty()){
                auto curr=q.front();q.pop();
                // cout<<curr<<endl;
                minm=min(c[curr-'a'].first,minm);
                maxm=max(c[curr-'a'].second,maxm);
                for(auto i:adj[curr]){
                    if(!visited[i-'a']){
                        visited[i-'a']=1;
                        q.push(i);
                    }
                }
            }
            st.insert({maxm-minm+1,minm});
        }
        vector<string>ans;vector<int> visited(n,0);set<pair<int,int>> taken;
        for(auto i:st){
            int ind=i.second,sz=i.first;
            int flg=1;
            for(int j=ind;j<=ind+sz-1;j++){
                if(visited[j]==1){
                    flg=0;break;
                }
            }
            if(!flg) continue;
            string v="";
            for(int j=ind;j<=ind+sz-1;j++){
                visited[j]=1;v+=s[j];
            }
            ans.push_back(v);
        }
        return ans;
    }
};