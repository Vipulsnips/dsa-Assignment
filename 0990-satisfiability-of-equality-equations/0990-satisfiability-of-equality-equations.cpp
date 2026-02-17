class Solution {
public:
    vector<int>parent;
    vector<int> rank;
    int find(int i){
        if(parent[i]==i) return i;
        return parent[i]=find(parent[i]);
    }
    void Union(int i,int j){
        int i_p=find(i);
        int j_p=find(j);
        if(i_p == j_p) return ;
        if(rank[i_p]>rank[j_p]) parent[j_p]=i_p;
        else if (rank[i_p]<rank[j_p]) parent[i_p]=j_p;
        else{
          parent[j_p]=i_p;
          rank[i_p]++;
        } 
    }
    bool equationsPossible(vector<string>& equations) {
        rank.assign(26,0);
        parent.resize(26);
        for(int i=0;i<26;i++) parent[i]=i; 
        for(auto i:equations){
            if(i[1]=='='){
                Union(i[0]-'a',i[3]-'a');
            }
        }
        for(auto i:equations){
            if(i[1]=='!'){
                if(find(i[0]-'a') == find(i[3]-'a')) return false;
            }
        }
        return true;
    }
};