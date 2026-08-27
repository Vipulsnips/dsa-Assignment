class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26,0);
        for(auto i:s) cnt[i-'a']++;
        int n=s.size();string ans="";
        for(int i=0;i<n;i++){
            char t=target[i];
            int curr=t-'a';
            if(cnt[curr]==0){
                string rem=target.substr(0,i);int flg=0;
                for(int j=curr;j<26;j++){
                    if(cnt[j]){
                        cnt[j]--;
                        rem+=char('a'+j);
                        flg=1;
                        break;
                    }
                }
                if(!flg) return ans;
                for(int j=0;j<26;j++){
                    if(cnt[j]) rem+=string(cnt[j],char('a'+j));
                }
                if(ans=="") ans=rem;
                else ans=min(ans,rem);
                return ans;
            }
            else{
                vector<int> temp=cnt;
                string rem=target.substr(0,i);int flg=0;
                cout<<curr<<" ";
                for(int j=curr+1;j<26;j++){
                    if(temp[j]){
                        temp[j]--;
                        rem+=char('a'+j);
                        flg=1;
                        break;
                    }
                }
                if(!flg) {
                    cnt[curr]--;
                    continue;
                }
                for(int j=0;j<26;j++){
                    if(temp[j]) rem+=string(temp[j],char('a'+j));
                }
                cout<<rem<<endl;
                if(ans=="") ans=rem;
                else ans=min(ans,rem);
                cnt[curr]--;
            }
        }
        if(ans!=target) return ans;
        else return "";
    }
};