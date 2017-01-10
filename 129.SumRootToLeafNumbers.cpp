class Solution 
{
public:
    int sumNumbers(TreeNode* root) 
    {
        if(root == NULL) return 0;
        int res = 0;
        solve(root, 0, res);
        return res;
    }
    void solve(TreeNode* root, int temp, int &res)
    {
    	if(!root->left && !root->right)
    	{
    		res += temp*10 + root->val;
    		return;
    	}
    	if(root->left) solve(root->left, temp*10+root->val, res);
    	if(root->right) solve(root->right, temp*10+root->val, res);
    }
};

class Solution 
{
public:
    int sumNumbers(TreeNode* root) 
    {
        if(root == NULL) return 0;
        return solve(root, 0);
    }
    int solve(TreeNode* root, int res)
    {
    	if(root == NULL)
    		return 0;
    	if(!root->left && !root->right)    		
    		return res * 10 + root->val;
    	return solve(root->left, res * 10 + root->val) + solve(root->right, res * 10  + root->val);
    }
};