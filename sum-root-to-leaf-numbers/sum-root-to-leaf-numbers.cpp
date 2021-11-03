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
    void helper(TreeNode *root, string &stk, int &res) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            stk += to_string(root->val);
            int tmp = stoi(stk);
            stk.pop_back();
            res += tmp;
            return;
        }
        stk += to_string(root->val);
        helper(root->left, stk, res);
        helper(root->right, stk, res);
        stk.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        string s;
        int res = 0;
        helper(root, s, res);
        return res;
    }
};