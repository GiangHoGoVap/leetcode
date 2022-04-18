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
    int ans = INT_MIN;
    int kthSmallest(TreeNode* root, int k) {
        ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        inorder(root, k);
        return ans;
    }
    void inorder(TreeNode* root, int &k){
        if(!root) return;
        inorder(root->left, k);
        k--;
        if(k == 0){
            ans = root->val;
            return;
        }
        inorder(root->right, k);
    }
};