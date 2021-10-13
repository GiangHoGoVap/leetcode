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
    void addToTree(TreeNode* r, TreeNode* n){
        if(n->val > r->val){
            if(!r->right) r->right = n;
            else addToTree(r->right, n);
        }
        else{
            if(!r->left) r->left = n;
            else addToTree(r->left, n);
        }
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(!preorder.size()) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i=1; i<preorder.size(); i++)
            addToTree(root, new TreeNode(preorder[i]));
        return root;
    }
};