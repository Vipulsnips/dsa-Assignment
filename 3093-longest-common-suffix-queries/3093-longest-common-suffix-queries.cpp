class Solution {
public:
    int n;
    vector<int> result;
    struct trieNode{
        int ind;
        trieNode * children[26];
    };
    trieNode * create(){
        trieNode * root=new trieNode;
        root->ind=-1;
        for(int i=0;i<26;i++) root->children[i]=NULL;
        return root;
    }
    void populate(trieNode * root,string & word){
        for(int i=word.size()-1;i>=0;i--){
            if(root->children[word[i]-'a']== NULL){
                root->children[word[i]-'a']=create();
            }
            root=root->children[word[i]-'a'];
        }
    }
    void find(trieNode * root,string & word,vector<string>& wordsContainer,int i,int curr){
        if(i<0 || (root->children[word[i]-'a']==NULL) ) return;
        root=root->children[word[i]-'a'];
        int ind=root->ind;
        if(ind==-1) root->ind=curr;
        else if(wordsContainer[ind].size() > wordsContainer[curr].size()) root->ind=curr;
        find(root,word,wordsContainer,i-1,curr);
    }
    void ans(trieNode * root,string & word){
        int val=-1;
        for(int i=word.size()-1;i>=0;i--){
            root=root->children[word[i]-'a'];
            if(root->ind !=-1) val=root->ind;
        }
        result.push_back(val);
    }
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        n=wordsQuery.size();
        trieNode * root =create();
        int maxm=INT_MAX,ind=-1;
        for(int i=0;i<n;i++){
            populate(root,wordsQuery[i]);
        }
        for(int i=0;i<wordsContainer.size();i++){
            if(wordsContainer[i].size()<maxm){
                maxm=wordsContainer[i].size();
                ind=i;
            }
            find(root,wordsContainer[i],wordsContainer,wordsContainer[i].size()-1,i);   
        }
        for(int i=0;i<n;i++){
            ans(root,wordsQuery[i]);
        }
        for(auto &i:result){
            if(i==-1) i=ind;
        }
        return result;
    }
};