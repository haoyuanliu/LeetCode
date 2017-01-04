/**
 * Definition for a binary tree node.
 * struct TreeNode 
 * {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
	TreeNode* left = NULL;
    TreeNode* right = NULL;
    TreeNode* pre = new TreeNode((1<<31));
    void recoverTree(TreeNode* root) 
    {
    	
        midOrder(root);
        swap(left->val, right->val);
    }

    void midOrder(TreeNode* root)
    {
    	if(root)
    	{
    		midOrder(root->left);
    		if(!left && pre->val >= root->val)
    			left = pre;
    		if(left && pre->val >= root->val)
    			right = root;
    		pre = root;
    		midOrder(root->right);
    	}
    }
};