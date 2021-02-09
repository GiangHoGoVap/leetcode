/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root, int& res)
    {
        if (!root) return 0;
        int l = height(root->left, res);
        int r = height(root->right, res);
        if (l + r > res) res = l + r;
        return 1 + max(l, r);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int res = INT_MIN;
        int ans = height(root, res);
        return res;
    }
};