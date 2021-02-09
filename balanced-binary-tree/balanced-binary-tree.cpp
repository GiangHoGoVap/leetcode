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
    bool isBalanced(TreeNode* root) {
        bool result = true;
        check(root, result);
        return result;
    }
    int check(TreeNode *root, bool &result) {
        if (root == NULL || result == NULL) return 0;
        int l = check(root->left, result) + 1;
        int r = check(root->right, result) + 1;
        int ans = abs(l - r);
        if (ans > 1) {
            result = false;
            return 0;
        }
        return max(l, r);
    }
};