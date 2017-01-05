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
    int maxDepth(TreeNode* root) 
    {
        return getDepth(root);
    }

    int getDepth(TreeNode* root)
    {
    	if(root)
    		return 1 + max(getDepth(root->left), getDepth(root->right));
    	return 0;
    }
};