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
int ans=-1;
typedef pair<int,int> p;
p solve(TreeNode* root){
    if(!root) return {INT_MAX,INT_MIN};
    p left= solve(root->left);
    p right= solve(root->right);
    if(left.first!=INT_MAX && left.second!=INT_MIN){
        ans=max(abs(root->val- left.first),ans);
        ans=max(abs(root->val- left.second),ans);
    }
    if(right.first!=INT_MAX && right.second!=INT_MIN){
        ans=max(abs(root->val- right.first),ans);
        ans=max(abs(root->val- right.second),ans);
    }
    int minm=min(min(left.first , right.first),root->val);
    int maxm=max(max(left.second,right.second),root->val );
    return {minm,maxm};
}
    int maxAncestorDiff(TreeNode* root) {
        solve(root);
        return ans;
    }
};