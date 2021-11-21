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
    unordered_map<int, int> mp;
    
    TreeNode* recurse(vector<int>& inorder,     int inLeft,     int inRight,
                      vector<int>& postorder,   int outLeft,    int outRight)
    {
        if( inLeft > inRight || outLeft > outRight) return NULL;
        
        if(inLeft == inRight) return (new TreeNode(inorder[inLeft]));
        
        TreeNode* root = new TreeNode(postorder[outRight]);
        int idx = mp[postorder[outRight]];
        
        root->left = recurse(inorder, inLeft, idx-1, postorder, outLeft, outLeft + idx - inLeft - 1);
        root->right = recurse(inorder, idx+1, inRight, postorder, outLeft + idx - inLeft, outRight - 1);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        int n = inorder.size();
        for(int i = 0; i<n; i++) mp[inorder[i]] = i;
        return recurse(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};