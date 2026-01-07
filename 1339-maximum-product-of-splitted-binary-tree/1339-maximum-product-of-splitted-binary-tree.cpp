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
int MOD=1e9 +7;
int change(TreeNode* root){
    if(!root) return 0;
    return root->val += change(root->left) + change(root->right);
}
long long bfs(TreeNode* root){
    long long total = root->val,ans= LLONG_MIN;
    queue <TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* curr= q.front();
        q.pop();
        ans=max(((total-curr->val)* (curr->val)),ans);
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
    return ans;
}
class Solution {
public:
    int maxProduct(TreeNode* root) {
        change(root);
        long long ans= bfs(root);
        return ans%MOD;
    }
};