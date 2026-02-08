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
 pair<int,int> balanced(TreeNode* root){
    if(!root) return {0,1};
    pair <int,int> left= balanced(root->left);
    pair <int,int> right= balanced(root->right);
    if(left.second ==0 || right.second==0){
        return {max(left.first , right.first) +1, 0 };
    }
    int x= abs(left.first - right.first);
    pair <int,int >ans;
    ans.first =max(left.first , right.first) +1;
    if(x<=1) ans.second = 1;
    else ans.second =0;
    return ans;
}
    bool isBalanced(TreeNode* root) {
        pair <int, int > ans= balanced (root);
        return ans.second;
    }
};