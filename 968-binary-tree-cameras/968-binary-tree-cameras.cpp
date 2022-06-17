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
    int res = 0;
    
    int dfs(TreeNode* root) {
        if (!root) return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        if (left == 1 || right == 1) {
            res++;
            return -1;
        }
        
        else if (left == -1 || right == -1)
            return 0;
        
        else return 1;
    }
    
public:
    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 1) res++;
        return res;
    }
};