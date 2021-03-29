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
private:
    vector<int> m_voyage;
    vector<int> res;
    int i = 0;
public:
    bool rec(TreeNode* root) {
        if (!root) return true;
        if (root->val != m_voyage[i++]) {
            return false;
        }
        if (root->left && root->left->val != m_voyage[i]) {
            res.push_back(root->val);
            return rec(root->right) && rec(root->left);
        }
        else
            return rec(root->left) && rec(root->right);
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        m_voyage = voyage;
        return rec(root) ? res : vector<int>{-1};
    }
};