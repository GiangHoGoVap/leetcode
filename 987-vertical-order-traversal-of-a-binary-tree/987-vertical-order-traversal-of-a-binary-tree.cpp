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
    struct trp {int x, y, val;};                                                      
    vector <trp> cord;                                          
    void dfs(TreeNode *node, int x, int y) {      
        cord.push_back({x, y, node->val});  
        if (node->left)  dfs(node->left , x - 1, y - 1);  
        if (node->right) dfs(node->right, x + 1, y - 1);  
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;       
        dfs(root, 0, 0);                                                               
        sort(cord.begin(), cord.end(), [](trp a, trp b){return a.x == b.x ? a.y == b.y ? a.val < b.val : a.y > b. y : a.x < b.x;}); 
        for (int i=0; i<cord.size();) {
            vector <int> aux;                 
            do { 
                aux.push_back(cord[i++].val);
            } 
            while (i<cord.size() and cord[i].x == cord[i-1].x); 
            ans.push_back(aux);            
        }
        return ans;
    }
};