class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxm) {
        vector<string> ans;
        int n=words.size(),curr=0;string s="";
        for(int i=0;i<n;){
            if(curr==0){
                s+=words[i];
                curr+=words[i].size();
                i++;
            }
            else if((curr+words[i].size()+1) <= maxm){
                s+=" "; 
                s+=words[i];
                curr+=(1+words[i].size());
                i++;
            }
            else{
                ans.push_back(s);
                curr=0;
                s="";
                continue;
            }
        }
        if(s!="") ans.push_back(s);
        int m=ans.size();
        for(int i=0;i<m;i++){
            int sp=count(ans[i].begin(),ans[i].end(),' ');
            int esp=maxm-ans[i].size();
            // cout<<sp<<" "<<esp<<endl;
            if(sp==0 || i==(m-1)){

                for(int cnt=1;cnt<=esp;cnt++) ans[i]+=" ";
            }
            else{
                int add=0;
                // if(sp==0) continue;
                if(sp>0) add=esp/sp;
                int v=esp%sp;
                cout<<v<<endl;
                int flg=0;
                for(int j=0;j<ans[i].size()-1;j++){
                    if(!flg && j+1<(ans[i].size()) && ans[i][j]!=' ' && ans[i][j+1]==' '){
                        int d=add;
                        if(v>0){
                            d++;
                            v--;
                        }
                        string t="";
                        for(int cnt=1;cnt<=d;cnt++) t+=" ";
                        ans[i].insert(j+1,t);
                        flg=1;
                    }
                    else if(flg && j+1<(ans[i].size()) && ans[i][j]!=' ' && ans[i][j+1]==' '){
                        int d=add;
                        if(v>0){
                            d++;
                            v--;
                        }
                        for(int cnt=1;cnt<=d;cnt++) ans[i].insert(j+1," ");
                    }
                }
            }
            // cout<<sp<<" "<<esp<<endl;
        }
        return ans;
    }
};