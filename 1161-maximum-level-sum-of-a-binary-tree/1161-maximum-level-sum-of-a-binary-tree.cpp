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
    int bfs(TreeNode* root){
        queue <TreeNode*> q;
        q.push(root);
        q.push(NULL);
        long long maxm=LLONG_MIN,level=-1,sum=0,cnt=1;
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(!curr){
                if(sum>maxm){
                    maxm=sum;
                    level=cnt;
                }
                cnt++;
                sum=0;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                sum+=curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return level;
    }
    int maxLevelSum(TreeNode* root) {
        int ans = bfs(root);
        return ans;
    }
};