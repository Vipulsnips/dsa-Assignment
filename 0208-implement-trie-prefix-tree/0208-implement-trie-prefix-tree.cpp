class Trie {
public:
    string word;
    Trie * children[26];
    bool exists;
    Trie() {
        for(int i=0;i<26;i++) children[i]=NULL;
        exists=false;
    }
    
    void insert(string word){
        Trie * temp = this;
        int n=word.size();
        for(int i=0;i<n;i++){
            if(temp->children[word[i]-'a']==NULL){
                cout<<word[i];
                temp->children[word[i]-'a'] = new Trie();
            }
            temp=temp->children[word[i]-'a'];
        }
        temp->exists=true;
        temp->word=word;
    }
    
    bool search(string word) {
        Trie * temp = this;
        for(int i=0;i<word.size();i++){
            if(temp->children[word[i]-'a']==NULL) return false;
            temp=temp->children[word[i]-'a'];
        }
        if(temp->exists) return true;
        else return false;
    }
    
    bool startsWith(string prefix) {
        Trie * temp = this;
        for(int i=0;i<prefix.size();i++){
            if(temp->children[prefix[i]-'a']==NULL) return false;
            temp=temp->children[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */