class Solution {
public:
    vector<string> result;
    int n,m;
    struct trieNode{
        string word;
        bool endword;
        trieNode * children[26];
    };
    trieNode * create(){
        trieNode * root=new trieNode;
        root->word="";
        root->endword=false;
        for(int i=0;i<26;i++) root->children[i]=NULL;
        return root;
    }
    void populate(trieNode * root,string &word){
        for(auto i:word){
            if(root->children[i-'a']==NULL){
                root->children[i-'a']=create();
            }
            root=root->children[i-'a'];
        }
        root->endword=true;
        root->word=word;
    }
    void find(vector<vector<char>>& board,trieNode * root,int i,int j){
        if((i<0 || i>=n) || (j<0 || j>=m)) return;
        if(board[i][j]=='$' || root->children[board[i][j]-'a']==NULL) return;
        root= root->children[board[i][j]-'a'];
        if(root->endword) {
            result.push_back(root->word);
            root->endword=false;
        }
        char curr=board[i][j];
        board[i][j]='$';
        find(board,root,i+1,j);
        find(board,root,i-1,j);
        find(board,root,i,j+1);
        find(board,root,i,j-1);
        board[i][j]=curr;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n=board.size();m=board[0].size();
        trieNode * root = create();
        for(auto i:words){
            populate(root,i);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                find(board,root,i,j);
            }
        }
        return result;
    }
};