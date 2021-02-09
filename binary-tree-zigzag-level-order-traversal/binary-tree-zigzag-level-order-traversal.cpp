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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> nodes;
        if (root) nodes.push(root);
        bool flag = false;
        while (!nodes.empty()){
            int size = nodes.size();
            vector<int> temp;
            while (size){
                TreeNode* curNode = nodes.front();
                temp.push_back(curNode->val);
                if (curNode->left) nodes.push(curNode->left);
                if (curNode->right) nodes.push(curNode->right);
                nodes.pop();
                size--;
            }
            if (flag) reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            flag = flag ? false : true;
        }
        return ans;
    }
};