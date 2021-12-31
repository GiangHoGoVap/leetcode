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
class Solution
{
public:
    int rec(TreeNode *root, int minval, int maxval)
    {
        if (!root)
        {
            return maxval - minval;
        }

        minval = min(minval, root->val);
        maxval = max(maxval, root->val);

        int left = rec(root->left, minval, maxval);
        int right = rec(root->right, minval, maxval);

        return max(left, right);
    }

    int maxAncestorDiff(TreeNode *root)
    {
        return rec(root, root->val, root->val);
    }
};