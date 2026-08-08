class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size(),m=word2.size(),j=0;
        vector<int> pre(n,0),suff(n,0);
        for(int i=0;i<n;i++){
            if(j<m && word1[i] == word2[j]){
                i==0?(pre[i]=1):pre[i]=pre[i-1]+1;
                j++;
            }
            else{
                i==0?(pre[i]=0):pre[i]=pre[i-1];
            }
        }
        j=m-1;
        for(int i=n-1;i>=0;i--){
            if(j>=0 && word1[i] == word2[j]){
                i==(n-1)?(suff[i]=1):suff[i]=suff[i+1]+1;
                j--;
            }
            else{
                i==(n-1)?(suff[i]=0):suff[i]=suff[i+1];
            }
        }
        j=0;
        vector<int> pos;
        for(int i=0;i<n-1;i++){
            if(pos.size()==word2.size()) break;
            if((i==0 && pre[i]==1) || (i>0 && pre[i-1]!=pre[i])){
                pos.push_back(i);
                continue;
            }
            if(pre[i]+suff[i] >= (m-1)){
                bool cant=false;
                i==0?cant=true:((pre[i-1]==pre[i])?cant=true:cant=false);
                if(!cant) continue;
                i==n-1?cant=true:((suff[i+1]==suff[i])?cant=true:cant=false);
                if(!cant) continue;
                pos.push_back(i);
                j=pre[i]+1;
                for(int k=i+1;k<n;k++){
                    if(word1[k]==word2[j]){
                        pos.push_back(k);
                        j++;
                    }
                }
                break;
            }
        }
        if(pos.size() != m) return {};
        return pos;
    }
};