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
    vector<vector<int>> ans;
    queue<TreeNode*> q;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return ans;
        q.push(root);
        while (q.empty() == false){
            int size = q.size();
            vector<int> tempans;
            for (int i=0; i<size; i++){
                TreeNode* node = q.front();
                tempans.push_back(node->val);
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(tempans);
        }
        return ans;
    }
};