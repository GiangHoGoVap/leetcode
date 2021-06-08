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
class Solution
{
public:
	TreeNode *buildBTree(vector<int> &preorder, vector<int> &inorder,
						 int &pre_idx, int inorder_start, int inorder_end)
	{
		if (inorder_start > inorder_end)
			return nullptr;

		TreeNode *root = new TreeNode(preorder[pre_idx]);

		int inorder_idx = inorder_start;
		for (int i = inorder_start; i <= inorder_end; i++)
			if (inorder[i] == preorder[pre_idx])
			{
				inorder_idx = i;
				break;
			}

		++pre_idx;

		root->left = buildBTree(preorder, inorder, pre_idx, inorder_start, inorder_idx - 1);
		root->right = buildBTree(preorder, inorder, pre_idx, inorder_idx + 1, inorder_end);
		return root;
	}

	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
	{
		int pre_idx = 0, inorder_start = 0, inorder_end = inorder.size() - 1;
		return buildBTree(preorder, inorder, pre_idx, inorder_start, inorder_end);
	}
};