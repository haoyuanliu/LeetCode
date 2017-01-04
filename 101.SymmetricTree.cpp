/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    bool isSymmetric(TreeNode* root)
    {
    	if(root == NULL)
    		return true;
        return isTheSame(root->left, root->right);
    }
	bool isTheSame(TreeNode* left, TreeNode* right)
	{
		if(left == NULL || right == NULL)
			return left == right;
		if(left->val != right->val)
			return false;
		return isTheSame(left->left, right->right) && isTheSame(left->right, right->left);
	}
};