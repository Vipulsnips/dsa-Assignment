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
    int maxm = INT_MAX;
    TreeNode* ans = nullptr;

    pair<int,int> check(TreeNode* root, set<TreeNode*>& s) {
        if (!root) return {0, 0};

        auto left  = check(root->left, s);
        auto right = check(root->right, s);

        int cnt  = left.first + right.first;
        int size = left.second + right.second;

        if (s.find(root) != s.end()) cnt++;
        size++;

        return {cnt, size};
    }

    void dfs(TreeNode* root, set<TreeNode*>& s) {
        if (!root) return;

        pair<int,int> temp = check(root, s);

        if (temp.first == (int)s.size() && temp.second < maxm) {
            maxm = temp.second;
            ans = root;
        }

        dfs(root->left, s);
        dfs(root->right, s);
    }

    void solve(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        set<TreeNode*> s;

        while (!q.empty()) {
            set<TreeNode*> temp;
            int size = q.size();

            while (size--) {
                TreeNode* curr = q.front();
                q.pop();

                temp.insert(curr);

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            s = temp; // deepest level nodes
        }

        dfs(root, s);
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        ans = root;
        solve(root);
        return ans;
    }
};
