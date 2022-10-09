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
    vector<int> a;
    void inorder(TreeNode *root) {
        if (root) {
            inorder(root->left);
            a.push_back(root->val);
            inorder(root->right);
        }
    }
    
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        set<int> m;
        for (int i = 0; i < a.size(); i++) {
            if (m.find(k-a[i]) != m.end()) return true;
            m.insert(a[i]);
        }
        return false;
    }
};