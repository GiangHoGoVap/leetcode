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
class BSTIterator {
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root) {
        findLeft(root);
    }
    
    void findLeft(TreeNode* root){
        TreeNode* temp = root;
        while (temp){
            s.push(temp);
            temp = temp->left;
        }
    }
    
    int next() {
        TreeNode* top = s.top();
        s.pop();
        if (top->right) findLeft(top->right);
        return top->val;
    }
    
    bool hasNext() {
        if (s.empty()) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */