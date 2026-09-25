class Solution {
public:
    set<string> solve(string & e,int i,int en){
        if(i>en) return {};
        set<string> ans,temp;
        for(int j=i;j<=en;){
            if(e[j]=='{'){
                int cnt=1,k=j+1;
                while(k<=en && cnt>0){
                    if(e[k]=='{') cnt++; else if(e[k]=='}') cnt--;
                    k++;
                }
                set<string> curr=solve(e,j+1,k-2);
                if(temp.size()==0) temp=curr;
                else{
                    set<string> nz;
                    for(auto t:temp){
                        for(auto c:curr) nz.insert(t+c);
                    }
                    temp=nz;
                }
                j=k;
            }
            else if(e[j]==','){
                for(auto t:temp) ans.insert(t);
                temp.clear();
                j++;
            }
            else{
                if(temp.size()==0) temp.insert({e[j]});
                else{
                    set<string> nz;
                    for(auto t:temp){
                        nz.insert(t+e[j]);
                    }
                    temp=nz;
                }
                j++;
            }
        }
        if(!temp.empty()){for(auto t:temp) ans.insert(t);}
        return ans;
    }
    vector<string> braceExpansionII(string expression) {
        set<string>s=solve(expression,0,expression.size()-1);
        vector<string> ans;
        for(auto i:s) ans.push_back(i);
        return ans;
    }
};