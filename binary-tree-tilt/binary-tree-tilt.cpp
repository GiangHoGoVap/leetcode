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
    int res = 0;
public:
    int recur(TreeNode* root){
        if (!root) return 0;
        int left = recur(root->left);
        int right = recur(root->right);
        int tilt = abs(left - right);
        res += tilt;
        return left + right + root->val;
    }
    
    int findTilt(TreeNode* root) {
        recur(root);
        return res;
    }
};