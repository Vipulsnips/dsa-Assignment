/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector <int> a;
    int n;
    void sort(TreeNode * root){
        if(!root) return;
        sort(root->left);
        a.push_back(root->val);
        sort(root->right);
    }
    TreeNode * create(vector <int> &a,int i,int j){
        if(i>j) return nullptr;
        int mid=(i+j)/2;
        TreeNode * root = new TreeNode (a[mid]);
        root->left = create(a,i,mid-1);
        root->right =create(a,mid+1,j);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        sort(root);
        n=a.size();
        TreeNode * build=create(a,0,a.size()-1);
        return build;
    }
};