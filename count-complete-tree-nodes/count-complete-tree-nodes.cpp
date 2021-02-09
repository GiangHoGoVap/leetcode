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
    int height(TreeNode* root,int k)
    {
        if (root==NULL) return 0;
        if (k==1) return 1 + height(root->left, 1);
        else return 1 + height(root->right, 0);
    }
    int countNodes(TreeNode* root) {
        if (root==NULL) return 0;
        int a = height(root, 1);
        int b = height(root, 0);
        if (a==b) return pow(2, a)-1;
        else return countNodes(root->left) + countNodes(root->right) + 1;
    }
};