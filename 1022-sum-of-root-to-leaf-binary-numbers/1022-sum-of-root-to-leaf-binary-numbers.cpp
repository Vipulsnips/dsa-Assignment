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
    typedef long long ll;
public:
    ll ans=0;
    void solve(TreeNode *root,string curr){
        curr+=to_string(root->val);
        if(!root->left && !root->right){
            ans+= stoll(curr,nullptr,2);
        }
        if(root->left){
            solve(root->left,curr);
        }
        if(root->right) {
            solve(root->right,curr);
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        solve(root,"");
        return ans;
    }
};