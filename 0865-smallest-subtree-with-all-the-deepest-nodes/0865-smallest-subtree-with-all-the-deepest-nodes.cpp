/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int,TreeNode *> check(TreeNode* root) {
        if (!root) return {0, NULL};
        auto left  = check(root->left);
        auto right = check(root->right);
        if(left.first > right.first) {
            return {left.first +1 ,left.second};
        }
        else if(left.first < right.first) return{right.first+1 ,right.second};
        else return{left.first +1 , root};
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        auto ans = check(root).second;
        return ans;
    }
};
