class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size(),m=word2.size(),j=0;
        vector<int> suff(n,0);
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
            if(word1[i]==word2[j]){
                pos.push_back(i);
                j++;
                continue;
            }
            if((i==n-1) || (j+suff[i+1])>= (m-1)){
                cout<<j<<suff[i+1]<<endl;
                pos.push_back(i);j++;
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