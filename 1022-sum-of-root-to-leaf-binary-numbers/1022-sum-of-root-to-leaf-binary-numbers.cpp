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
    void traverse(TreeNode* node, string sum) {
        if (!node)
            return;
        sum = sum + to_string(node->val);
        if (!node->left && !node->right)
        {
            vec.push_back(sum);
        }
        traverse(node->left, sum);
        traverse(node->right, sum); 
        
    }
    
    int sumRootToLeaf(TreeNode* root) {
        traverse(root, "");
        int res = 0;
        for(auto x:vec)
            res += stoi(x, nullptr, 2);
        return res;
    }
    vector<string> vec;
};