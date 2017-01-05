class Solution 
{
public:
    int minDepth(TreeNode* root) 
    {
        if(root == NULL)
    	    return 0;
    	if(!root->left && !root->right)
    		return 1;
    	else if(root->left && !root->right)
    	    return 1 + minDepth(root->left);
    	else if(!root->left && root->right)
    	    return 1 + minDepth(root->right);
    	return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};