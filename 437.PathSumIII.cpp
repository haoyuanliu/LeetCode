class Solution
{
public:
    int pathSum(TreeNode* root, int sum)
    {
    	if(root == NULL)
    		return 0;
        return solve(root, sum, 0) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    int solve(TreeNode* root, int target, int sum)
    {
    	if(root == NULL)
    		return 0;
    	if(sum + root->val == target)
    		return 1 + solve(root->left, 0, 0) + solve(root->right, 0, 0);
    	return solve(root->left, target, sum+root->val) + solve(root->right, target, sum+root->val);
    }
};
