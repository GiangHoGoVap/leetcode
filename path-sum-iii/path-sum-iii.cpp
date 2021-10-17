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
    void pathSum(int sum, TreeNode *root, std::unordered_map<int, int> &presum, int &cnt, const int target) {
        if (!root) return;
        
        sum += root->val;
        if (presum.count(sum - target)) {
            cnt += presum[sum - target];
        }
        presum[sum]++;
        
        pathSum(sum, root->left, presum, cnt, target);
        pathSum(sum, root->right, presum, cnt, target);
        
        presum[sum]--;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        
        std::unordered_map<int, int> mem;
        mem[0] = 1;
        int cnt = 0;
        pathSum(0, root, mem, cnt, sum);
        
        return cnt;
    }
};