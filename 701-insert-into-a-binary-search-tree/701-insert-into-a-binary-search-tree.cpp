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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        if (root == NULL) return newNode;
        else{
            TreeNode* pWalker = root;
            TreeNode* parent;
            while (pWalker){
                parent = pWalker;
                if (newNode->val < pWalker->val) pWalker = pWalker->left;
                else pWalker = pWalker->right;
            }
            if (newNode->val < parent->val) parent->left = newNode;
            else parent->right = newNode;
        }
        return root;
    }
};