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
    void insert(TreeNode* root, int val, int depth, int d){
        if (root == NULL) return;
        if (depth == d-1) {
            TreeNode* temp = root->left;
            root->left = new TreeNode(val);
            root->left->left = temp;
            temp = root->right;
            root->right = new TreeNode(val);
            root->right->right = temp;
        }
        else {
            insert(root->left, val, depth+1, d);
            insert(root->right, val, depth+1, d);
        }
    }
    
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* newNode = new TreeNode(v);
            newNode->left = root;
            return newNode;
        }
        insert(root, v, 1, d);
        return root;
    }
};