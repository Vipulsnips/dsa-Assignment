class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char,int> mp,mp2;int n=word.size(),ans=0;
        for(auto i:word){
            if(i>='a' && i<='z') mp[i]++;
        }
        for(int i=0;i<n;i++){
            if(word[i]>='A' && word[i]<='Z'){
                int x= word[i]-'A';
                if(mp[word[i]]==0 && mp['a'+x]==mp2['a'+x] && mp['a'+x]){
                    cout<<i;
                    ans++;
                }
                mp[word[i]]++;
            }
            else{
                mp2[word[i]]++;
            }
        }
        return ans;
    }
};