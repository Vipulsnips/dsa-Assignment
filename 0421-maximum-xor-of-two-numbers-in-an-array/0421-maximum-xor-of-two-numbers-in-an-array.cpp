class Solution {
public:
    int ans=0;
    struct Trie{
        Trie* children[2];
        int number;
        bool exists;
    };
    Trie* create(){
        Trie* root = new Trie();
        root->children[0]=NULL;root->children[1]=NULL;
        root->exists=false;
        return root;
    }
    void insert(int x,Trie * root){
        for(int i=31;i>=0;i--){
            int id = ((1<<i)&x)?1:0;
            if(root->children[id]==NULL) root->children[id]=create();
            root=root->children[id];
        }
        root->exists=true;
        root->number=x;
    }
    void find(int x,Trie * root){
        for(int i=31;i>=0;i--){
            int id = ((1<<i)&x)?0:1;
            if(root->children[id]==NULL){
                if(root->children[1-id]) root=root->children[1-id];
                else return;
            }
            else root=root->children[id];
            if(root->exists){
                // cout<<root->number<<x<<endl;
                ans=max(ans,root->number^x);
            }
        }
    }
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        Trie * root=create();
        for(int i=0;i<n;i++){
            insert(nums[i],root);
        }
        for(int i=0;i<n;i++){
            find(nums[i],root);
        }

        return ans;
    }
};