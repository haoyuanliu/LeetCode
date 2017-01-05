class Solution 
{
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        vector<vector<int>> res;
        vector<int> temp;
        solve(res, temp, root, sum);
        return res;
    }
    void solve(vector<vector<int>> &res, vector<int> &temp, TreeNode* root, int sum)
    {
    	if(root == NULL)
    		return;
    	if(!root->left && !root->right)
    	{
    		if(root->val == sum)
    		{
	    		temp.push_back(root->val);
	    		res.push_back(temp);
	    		temp.erase(temp.end()-1);
	    	}
	    	return;
    	}
    	if(root->left)
    	{
    		temp.push_back(root->val);
    		solve(res, temp, root->left, sum-root->val);
    		temp.erase(temp.end()-1);
    	}
    	if(root->right)
    	{
    		temp.push_back(root->val);
    		solve(res, temp, root->right, sum-root->val);
    		temp.erase(temp.end()-1);
    	}
    }
};