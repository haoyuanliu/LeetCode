class Solution 
{
public:
    bool hasPathSum(TreeNode* root, int sum) 
    {
    	if(root == NULL)
    		return false;
    	return solve(root, 0, sum);
    }
    bool solve(TreeNode* root, int sum, int target)
    {
    	if(!root->left && !root->right)
    		return sum+root->val == target;
    	else if(root->left && !root->right)
    		return solve(root->left, sum+root->val, target);
    	else if(!root->left && root->right)
    		return solve(root->right, sum+root->val, target);
    	return solve(root->left, sum+root->val, target) || solve(root->right, sum+root->val, target);
    }
};