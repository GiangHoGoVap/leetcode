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
    TreeNode* convertBST(TreeNode* root) {
        TreeNode* temp = root;
        stack<TreeNode*> s;
        int sum;
        while (!s.empty() || temp){
            if (temp){
                s.push(temp);
                temp = temp->right;
            }
            else{
                temp = s.top()->left;
                int tmp = sum;
                sum += s.top()->val;
                s.top()->val += tmp;
                s.pop();
            }
        }
        return root;
    }
};