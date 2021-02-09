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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) return false;
        else{
            bool ans = false;
            int subSum = sum - root->val;
            if (subSum == 0 && root->left == nullptr && root->right == nullptr) return true;
            if (root->left){
                ans = ans || hasPathSum(root->left, subSum);
            }
            if (root->right){
                ans = ans || hasPathSum(root->right, subSum);
            }
            return ans;
        }
    }
};